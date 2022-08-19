#include "weighing.h"
#include "ui_weighing.h"

#include "unlock.h"

#include <QtCore>
#include <QtGui>

#include <qmath.h>

weighing::weighing(QWidget *parent, QString user) :
    QDialog(parent),
    ui(new Ui::weighing)
{
    int itemflag = 0;

    read_flag = 0;
    stopclick_check = 0;

    t1=0; t2=0; t3=0; flw = 0;
    T11=0; T12=0; T21=0; T22=0; T31=0; T32=0;
    min = 0; max = 0; mean = 0; diff = 0;
    total = 0; percent = 0;

    lt1 = 0;
    lt2 = 0;
    lt3 = 0;
    gt1 = 0;
    gt2 = 0;
    gt3 = 0;

    timer = new QTimer(this);
    QTimer *qtimer = new QTimer(this);

    serial_timer = new QTimer(this);
    serial_timer->setInterval(250);

    connect(qtimer, SIGNAL(timeout()), this, SLOT(update_time()));
    connect(timer, SIGNAL(timeout()), this, SLOT(read_weight()));
    connect(serial_timer, SIGNAL(timeout()), this, SLOT(onReadyRead()));
    qtimer->start(1000);

    PortSettings portsettings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort("COM1", portsettings, QextSerialPort::Polling);

    db = QSqlDatabase :: database("database");
    qry = QSqlQuery(db);

    ui->setupUi(this);

    ui->loggedintime->setText(QTime::currentTime().toString("h:mm ap"));
    ui->currentuser->setText(user);
    ui->activebatchgroup->setDisabled(1);

    qry.prepare( "SELECT batchid FROM "+ui->currentuser->text()+" WHERE id = 1" );
    if( !qry.exec() )
          qDebug() << qry.lastError();
    else
    {
        while (qry.next())
        {
            itemflag = 1;
            ui->batchidcombobox->addItem(qry.value(0).toString());
        }
        if(itemflag == 0)
            ui->batchidcombobox->addItem("<Empty>");
    }

    if (!port->isOpen())
    {
          port->open(QIODevice::ReadWrite);
    }
}

weighing::~weighing()
{
    port->close();
    delete inputs;
    delete ui;
}

void weighing::onReadyRead()
{
    int flag=0;
    QString value,final;
        int i=0;
        double weight;
        while(!port->bytesAvailable());

        value=port->readAll();      // Receiving entire data from serial port

/*******************************************************************

Following for-loop formats 'value' based on Sansui input

*********************************************************************/

        for(i=1;i>=0;i++)
            {
                if(value[i] == '\n')
                {
                    flag = 1;
                    break;
                }
                else if(i>20)
                    break;

                final[i]=value[i];
            }

/*******************************************************************

'final' is the final formatted string.

********************************************************************/

            weight = final.toFloat();
            weight = weight-trw;
            ui->lastweight->setText(QString::number(last_weight,'f',3));
            ui->currentweight->setText(QString::number(weight,'f',3));

            if(weight != last_weight && flag == 1 && read_flag == 1) // Start weighing only when tablet is placed, this is for only first time
            {
                ui->messagelabel->clear();
                timer->start(period);
                read_flag = 0;
            }
}

void weighing::update_time()
{
    ui->timeupdatelabel->setText(QTime::currentTime().toString("h:mm:ss ap"));
    ui->dateupdatelabel->setText(QDate::currentDate().toString("d MMM yyyy"));
}

void weighing::read_weight()
{

    double temp = 0;
    timer->stop();
    const char new_line=0x0A;
    const char tab=0x09;
    char str1[100];
    char str2[100];

    QString data1;
    QString data2;

    QString value,final;
        int i=0; //,j=0,l=0,z_flag =0;
        double weight;
        while(!port->bytesAvailable());
        value=port->readAll();// Receiving entire data from serial port

/*******************************************************************

Following for-loop formats 'value' based on Sansui input

*********************************************************************/

        for(i=1;i>=0;i++)
        {
            if(value[i] == '\n')
            {
                break;
            }
            else if(i>20)
                break;

            final[i]=value[i];
        }

/*******************************************************************

'final' is the final formatted string.

********************************************************************/

         weight = final.toFloat();
         weight = weight-trw;
         temp = weight - last_weight;

         if(temp > (current_weight*0.8))  // Print only when current wight is 80%+ of last weight
         {
             last_weight = weight;
             current_weight = temp;
             total = total + current_weight;

             if(first_read == 0)
             {
                 min = current_weight;
                 max = current_weight;
                 first_read = 1;
                 port->write(&new_line,1);
                 port->write(&new_line,1);
             }

             *(inputs +(count -1)) = current_weight;

             if(current_weight < min)
                 min = current_weight;

             if(current_weight > max)
                 max = current_weight;

             if(current_weight < T31)
             {
                 lt3++;
                 ui->ltt3->setText(QString::number(lt3));
             }
             else if(current_weight < T21)
             {
                 lt2++;
                 ui->ltt2->setText(QString::number(lt2));
             }
             else if(current_weight < T11)
             {
                 lt1++;
                 ui->ltt1->setText(QString::number(lt1));
             }
             else if(current_weight > T32)
             {
                 gt3++;
                 ui->gtt3->setText(QString::number(gt3));
             }
             else if(current_weight > T22)
             {
                 gt2++;
                 ui->gtt2->setText(QString::number(gt2));
             }
             else if(current_weight > T12)
             {
                 gt1++;
                 ui->gtt1->setText(QString::number(gt1));
             }

             if(count < 10)
             {
                 ui->weightdisplayedit->insertPlainText("  "+QString::number(count)+".\t"+QString::number(current_weight,'f',3)+" g\n");
                 data1 = "  "+QString::number(count)+".";
             }
             else if(count >= 10 && count < 100)
             {
                 ui->weightdisplayedit->insertPlainText(" "+QString::number(count)+".\t"+QString::number(current_weight,'f',3)+" g\n");
                 data1 = " "+QString::number(count)+".";
             }
             else
             {
                 ui->weightdisplayedit->insertPlainText(QString::number(count)+".\t"+QString::number(current_weight,'f',3)+"  "+" g\n");
                 data1 = QString::number(count)+".";
             }

             data2 = QString::number(current_weight,'f',3)+" g";

             for(i=0;i<data1.length();i++)
                 str1[i]=data1[i].toAscii();

             for(i=0;i<data2.length();i++)
                 str2[i]=data2[i].toAscii();

             port->write(str1,data1.length());
             port->write(&tab,1);
             port->write(str2,data2.length());
             port->write(&new_line,1);
             port->write(&new_line,1);
             count++;
         }

         if((count-1)== limit)
             on_stopbutton_clicked();
         else
         {
             ui->messagelabel->setText("Next &tablet");
             //serial_timer->start();
             read_flag = 1;
         }

}

void weighing::on_okbutton_clicked()
{

    qry.prepare( "SELECT * FROM "+ui->currentuser->text()+" WHERE batchid = :batch" );
     qry.bindValue(":batch", ui->batchidcombobox->currentText());
     if( !qry.exec() )
           qDebug() << qry.lastError();
     else
     {
         qry.first();
         ui->batchidcombobox->setDisabled(1);
         ui->okbutton->setDisabled(1);
         ui->activebatchgroup->setEnabled(1);
         ui->startbutton->setEnabled(1);
         ui->stopbutton->setDisabled(1);
         ui->countedit->setEnabled(1);
         ui->endbatch->setEnabled(1);

         serial_timer->start();

         if(qry.value(1).toInt() == 1 )
         {
             ui->para_1->setText(qry.value(2).toString()+" :");
             ui->value_1->setText(" "+qry.value(3).toString());
         }
         else
         {
             ui->para_1->clear();
             ui->value_1->clear();
         }

         if(qry.value(4).toInt() == 1 )
         {
             ui->para_2->setText(qry.value(5).toString()+" :");
             ui->value_2->setText(" "+qry.value(6).toString());
         }
         else
         {
             ui->para_2->clear();
             ui->value_2->clear();
         }

         if(qry.value(7).toInt() == 1 )
         {
             ui->para_3->setText(qry.value(8).toString()+" :");
             ui->value_3->setText(" "+qry.value(9).toString());
         }
         else
         {
             ui->para_3->clear();
             ui->value_3->clear();
         }

         if(qry.value(10).toInt() == 1 )
         {
             ui->para_4->setText(qry.value(11).toString()+" :");
             ui->value_4->setText(" "+qry.value(12).toString());
         }
         else
         {
             ui->para_4->clear();
             ui->value_4->clear();
         }

         if(qry.value(13).toInt() == 1 )
         {
             ui->para_5->setText(qry.value(14).toString()+" :");
             ui->value_5->setText(" "+qry.value(15).toString());
         }
         else
         {
             ui->para_5->clear();
             ui->value_5->clear();
         }

         if(qry.value(16).toInt() == 1 )
         {
             ui->para_6->setText(qry.value(17).toString()+" :");
             ui->value_6->setText(" "+qry.value(18).toString());
         }
         else
         {
             ui->para_6->clear();
             ui->value_6->clear();
         }

         if(qry.value(19).toInt() == 1 )
         {
             ui->para_7->setText(qry.value(20).toString()+" :");
             ui->value_7->setText(" "+qry.value(21).toString());
         }
         else
         {
             ui->para_7->clear();
             ui->value_7->clear();
         }

         if(qry.value(22).toInt() == 1 )
         {
             ui->para_8->setText(qry.value(23).toString()+" :");
             ui->value_8->setText(" "+qry.value(24).toString());
         }
         else
         {
             ui->para_8->clear();
             ui->value_8->clear();
         }

         if(qry.value(25).toInt() == 1 )
         {
             ui->para_9->setText(qry.value(26).toString()+" :");
             ui->value_9->setText(" "+qry.value(27).toString());
         }
         else
         {
             ui->para_9->clear();
             ui->value_9->clear();
         }

         if(qry.value(28).toInt() == 1 )
         {
             ui->para_10->setText(qry.value(29).toString()+" :");
             ui->value_10->setText(" "+qry.value(30).toString());
         }
         else
         {
             ui->para_10->clear();
             ui->value_10->clear();
         }

         ui->fillweight->setText(" "+QString::number(qry.value(31).toFloat(),'f',3)+" g");
         ui->tareweight->setText(" "+QString::number(qry.value(32).toFloat(),'f',3)+" g");

         flw = qry.value(31).toFloat();
         trw = qry.value(32).toFloat();

         t1 = qry.value(33).toFloat();
         t2 = qry.value(34).toFloat();
         t3 = qry.value(35).toFloat();

         T11 = flw -(flw*(t1/100));
         T12 = flw +(flw*(t1/100));

         T21 = flw -(flw*(t2/100));
         T22 = flw +(flw*(t2/100));

         T31 = flw -(flw*(t3/100));
         T32 = flw +(flw*(t3/100));

         ui->tolerance31->setText(" "+QString::number(qry.value(35).toInt())+" %\t"+QString::number(T31,'f',3)+" g");
         ui->tolerance21->setText(" "+QString::number(qry.value(34).toInt())+" %\t"+QString::number(T21,'f',3)+" g");
         ui->tolerance11->setText(" "+QString::number(qry.value(33).toInt())+" %\t"+QString::number(T11,'f',3)+" g");
         ui->tolerance12->setText(" "+QString::number(qry.value(33).toInt())+" %\t"+QString::number(T12,'f',3)+" g");
         ui->tolerance22->setText(" "+QString::number(qry.value(34).toInt())+" %\t"+QString::number(T22,'f',3)+" g");
         ui->tolerance32->setText(" "+QString::number(qry.value(35).toInt())+" %\t"+QString::number(T32,'f',3)+" g");

     }
}

void weighing::on_startbutton_clicked()
{
    if(!ui->countedit->text().isEmpty())
    {
        inputs = new double[ui->countedit->text().toInt()];
        limit = ui->countedit->text().toInt();
        ui->countedit->setDisabled(1);

        count = 1;

        stopclick_check = 0;

        const char new_line=0x0A;
        const char tab=0x09;
        char str1[100];
        char str2[100];

        QString data1;
        QString data2;

        QString value,final;
        int i=0;
        double weight;

        ui->stoptime->clear();
        ui->weightdisplayedit->clear();

        port->write(&new_line,1);
        port->write(&new_line,1);
        port->write(&new_line,1);

        qry.prepare( "SELECT * FROM "+ui->currentuser->text()+" WHERE batchid = :batch" );
        qry.bindValue(":batch", ui->batchidcombobox->currentText());
        if( !qry.exec() )
            qDebug() << qry.lastError();
        else
        {
            qry.first();
            ui->starttime->setText(QTime::currentTime().toString("h:mm ap"));

            /*data1="   *****SAMPLE*****";
            data2="----------------------";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();

            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();

            port->write(str1,data1.length());
            port->write(&new_line,1);
            port->write(str2,data2.length());
            port->write(&new_line,1);
            */

            data1=QDate::currentDate().toString("dd/MM/yyyy")+"   "+ ui->starttime->text();

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();

            port->write(str1,data1.length());
            port->write(&new_line,1);
            port->write(&new_line,1);



            data1="BATCH ID  :"+ui->batchidcombobox->currentText();

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();

            port->write(str1,data1.length());
            port->write(&new_line,1);

            if(qry.value(1).toInt() == 1 )
            {
                data1=qry.value(2).toString()+" : "+qry.value(3).toString();
                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());
                /*
            if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(3).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(3).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(3).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(3).toString();


            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());*/
            if(data1.length()<15)
                port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(4).toInt() == 1 )
            {
                data1=qry.value(5).toString()+" : "+qry.value(6).toString();

                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());
                /*
            if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(6).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(6).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(6).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(6).toString();


            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(7).toInt() == 1 )
            {
                data1=qry.value(8).toString()+" : "+qry.value(9).toString();

                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /*           if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(9).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(9).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(9).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(9).toString();



            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                //port->write(&new_line,1);
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(10).toInt() == 1 )
            {
                data1=qry.value(11).toString()+" : "+qry.value(12).toString();

                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /*  if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(12).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(12).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(12).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(12).toString();


            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
               // port->write(&new_line,1);
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(13).toInt() == 1 )
            {
                data1=qry.value(14).toString()+" : "+qry.value(15).toString();

                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /*        if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(15).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(15).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(15).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(15).toString();



            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                //port->write(&new_line,1);
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(16).toInt() == 1 )
            {
                data1=qry.value(17).toString()+" : "+qry.value(18).toString();

                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /* if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(18).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(18).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(18).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(18).toString();


            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                //port->write(&new_line,1);
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(19).toInt() == 1 )
            {
                data1=qry.value(20).toString()+" : "+qry.value(21).toString();

                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /*   if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(21).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(21).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(21).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(21).toString();



            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                //port->write(&new_line,1);
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(22).toInt() == 1 )
            {
                data1=qry.value(23).toString()+" : "+qry.value(24).toString();
                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /*  if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(24).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(24).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(24).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(24).toString();


            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                //port->write(&new_line,1);
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(25).toInt() == 1 )
            {
                data1=qry.value(26).toString()+" : "+qry.value(27).toString();
                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /*    if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(27).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(27).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(27).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(27).toString();



            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                //port->write(&new_line,1);
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            if(qry.value(28).toInt() == 1 )
            {
                data1=qry.value(29).toString()+" : "+qry.value(30).toString();
                for(i=0;i<data1.length();i++)
                    str1[i]=data1[i].toAscii();
                port->write(str1,data1.length());

                /*   if(data1.length()<8)
            {
                port->write(&tab,1);
                data2="    "+qry.value(30).toString();
            }
            else if(data1.length() == 8)
                data2="    "+qry.value(30).toString();
            else if(data1.length() == 9)
                data2="   "+qry.value(30).toString();
            else if(data1.length() == 10)
                data2="  "+qry.value(30).toString();



            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            if(data2.length()>=7)*/
                if(data1.length()<15)
                    port->write(&new_line,1);
                port->write(&new_line,1);
            }

            //port->write(&new_line,1);
            port->write(&new_line,1);

            data1="Fill Wt   :"+QString::number(qry.value(31).toFloat(),'f',3)+"g";
            //flw = qry.value(31).toFloat();

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&new_line,1);

            data1="Tare Wt   :"+QString::number(qry.value(32).toFloat(),'f',3)+"g";
            //trw = qry.value(32).toFloat();

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();

            port->write(str1,data1.length());
            port->write(&new_line,1);
            port->write(&new_line,1);

            //port->write(right,3);

            data1="T3-:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            if(qry.value(35).toInt() < 10)
                data2=" "+qry.value(35).toString()+" % "+QString::number(T31,'f',3)+"g";
            else
                data2=qry.value(35).toString()+" % "+QString::number(T31,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();

            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1="T2-:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);


            if(qry.value(34).toInt() < 10)
                data2=" "+qry.value(34).toString()+" % "+QString::number(T21,'f',3)+"g";
            else
                data2=qry.value(34).toString()+" % "+QString::number(T21,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();

            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1="T1-:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);


            if(qry.value(33).toInt() < 10)
                data2=" "+qry.value(33).toString()+" % "+QString::number(T11,'f',3)+"g";
            else
                data2=qry.value(33).toString()+" % "+QString::number(T11,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();

            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1="T1+:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);


            if(qry.value(33).toInt() < 10)
                data2=" "+qry.value(33).toString()+" % "+QString::number(T12,'f',3)+"g";
            else
                data2=qry.value(33).toString()+" % "+QString::number(T12,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();

            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1="T2+:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);


            if(qry.value(34).toInt() < 10)
                data2=" "+qry.value(34).toString()+" % "+QString::number(T22,'f',3)+"g";
            else
                data2=qry.value(34).toString()+" % "+QString::number(T22,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();

            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);

            data1="T3+:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);


            if(qry.value(35).toInt() < 10)
                data2=" "+qry.value(35).toString()+" % "+QString::number(T32,'f',3)+"g";
            else
                data2=qry.value(35).toString()+" % "+QString::number(T32,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();

            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);
            port->write(&new_line,1);
        }

        while(!port->bytesAvailable());
        value=port->readAll();

        for(i=1;i>=0;i++)
        {
            if(value[i] == '\n')
            {
                //final[i] = '\0';
                break;
            }
            else if(i>20)
                break;

            final[i]=value[i];
        }


        weight = final.toFloat();

        last_weight = weight;
        current_weight = 0;
        mean =0;
        total = 0;
        diff = 0;

        qry.prepare("SELECT interval FROM settings WHERE id=1");
        if(!qry.exec())
            qDebug("Error at prefer");
        else
        {
            qry.first();
            if( qry.value(0).toInt() == 2 )
            {
                //timer->start(2000);
                period = 2000;
            }
            else if( qry.value(0).toInt() == 3 )
            {
                //timer->start(3000);
                period = 3000;
            }
            else if( qry.value(0).toInt() == 4 )
            {
                //timer->start(4000);
                period = 4000;
            }
        }

        ui->startbutton->setDisabled(1);
        ui->stopbutton->setEnabled(1);

        ui->messagelabel->setText("Next &tablet");
        first_read = 0;
        read_flag = 1;
    }
    else
        QMessageBox::critical(this, "Field Empty", "No.of samples can't be empty");
}

void weighing::on_stopbutton_clicked()
{
    if(count>1)
    {
        read_flag = 0;
        const char new_line={0x0A};
        const char tab={0x09};
        //char left[]={0x1B,0x61,0x00};
        //char right[]={0x1B,0x61,0x02};
        char str1[100];
        char str2[100];

        double sum =0;

        QString data1;
        QString data2;

        int i=0,j=0;

        stopclick_check = 1;
        ui->endbatch->setEnabled(1);
        ui->messagelabel->clear();
        //serial_timer->stop();
        timer->stop();

        diff = max - min;

        if(count>1)
            count = count - 1;

        mean = total/count;

        for(j=0;j<count;j++)
            *(inputs + j) = ((*(inputs + j) - mean)*(*(inputs + j) - mean));


        for(i=0;i<count;i++)
            sum = sum +(*(inputs + j));

        if(count > 1)
            sum = sum/(count - 1);
        else
            sum = 0;

        sum = qSqrt(sum);

        percent = (mean/flw)*100;

        data1="Mean:";
        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(percent,'f',3)+"% "+QString::number(mean,'f',3)+"g";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);

        percent = (sum/flw)*100;

        data1="SD  :";
        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(percent,'f',3)+"% "+QString::number(sum,'f',3)+"g";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);

        percent = (min/flw)*100;

        data1="Min :";
        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(percent,'f',3)+"% "+QString::number(min,'f',3)+"g";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);

        percent = (max/flw)*100;


        data1="Max :";
        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(percent,'f',3)+"% "+QString::number(max,'f',3)+"g";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);

        percent = (diff/flw)*100;

        data1="Diff:";
        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(percent,'f',3)+"% "+QString::number(diff,'f',3)+"g";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);
        port->write(&new_line,1);


        data1="<T3-: ";

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(lt3)+"    "+QString::number(((lt3/count)*100),'f',3)+"%";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);


        data1="<T2-: ";

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(lt2)+"    "+QString::number(((lt2/count)*100),'f',3)+"%";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);


        data1="<T1-: ";

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(lt1)+"    "+QString::number(((lt1/count)*100),'f',3)+"%";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);


        data1=">T1+: ";

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(gt1)+"    "+QString::number(((gt1/count)*100),'f',3)+"%";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);


        data1=">T2+: ";

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(gt2)+"    "+QString::number(((gt2/count)*100),'f',3)+"%";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);


        data1=">T3+: ";

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();
        port->write(str1,data1.length());
        port->write(&tab,1);

        data2=QString::number(gt3)+"    "+QString::number(((gt3/count)*100),'f',3)+"%";
        for(i=0;i<data2.length();i++)
            str2[i]=data2[i].toAscii();
        port->write(str2,data2.length());
        port->write(&new_line,1);
        port->write(&new_line,1);
        port->write(&new_line,1);


        ui->stoptime->setText(QTime::currentTime().toString("h:mm ap"));
        data1=QDate::currentDate().toString("dd/MM/yyyy")+"   "+ui->stoptime->text();

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();

        port->write(str1,data1.length());
        port->write(&new_line,1);
        port->write(&new_line,1);

        data1="OPERATOR SIGN";

        for(i=0;i<data1.length();i++)
            str1[i]=data1[i].toAscii();

        port->write(str1,data1.length());
        port->write(&new_line,1);
        port->write(&new_line,1);
        port->write(&new_line,1);
        port->write(&new_line,1);
        port->write(&new_line,1);
        port->write(&new_line,1);


        ui->stopbutton->setDisabled(1);
        ui->startbutton->setEnabled(1);

        last_weight = 0;

        t1=0;
        t2=0;
        t3=0;
        flw = 0;
        T11=0;
        T12=0;
        T21=0;
        T22=0;
        T31=0;
        T32=0;
        min = 0;
        max = 0;
        mean = 0;
        diff = 0;
        total = 0;
        percent = 0;

        lt1 = 0;
        lt2 = 0;
        lt3 = 0;
        gt1 = 0;
        gt2 = 0;
        gt3 = 0;

        count = 1;

        ui->countedit->clear();
        ui->countedit->setEnabled(1);
    }
}

void weighing::on_lockbutton_clicked()
{
    if(ui->lockbutton->text() == "Lock Session")
    {
        timer->stop();
        ui->batchidcombobox->setDisabled(1);
        ui->okbutton->setDisabled(1);
        ui->activebatchgroup->setDisabled(1);
        ui->lockbutton->setText("Unlock");
        serial_timer->stop();
    }
    else
    {
        unlock lock(this,ui->currentuser->text());
        lock.setModal(true);
        if(lock.exec() == QDialog::Accepted )
        {
            ui->batchidcombobox->setEnabled(1);
            ui->okbutton->setEnabled(1);
            ui->activebatchgroup->setEnabled(1);
            ui->lockbutton->setText("Lock Session");
            timer->start(period);            
            serial_timer->start();
        }
    }

}

void weighing::on_endbatch_clicked()
{
    read_flag = 0;
    serial_timer->stop();

    stopclick_check = 0;

    ui->batchidcombobox->setEnabled(1);
    ui->okbutton->setEnabled(1);

    if(count >1)
    {
        const char new_line={0x0A};
        const char tab={0x09};
        //char left[]={0x1B,0x61,0x00};
        //char right[]={0x1B,0x61,0x02};
        char str1[100];
        char str2[100];

        QString data1;
        QString data2;

        int i=0,j=0;
        double sum =0;


        if(stopclick_check == 1)
        {

            diff = max - min;
            count = count - 1;

            mean = total/count;

            for(j=0;j<count;j++)
                *(inputs + j) = ((*(inputs + j) - mean)*(*(inputs + j) - mean));


            for(i=0;i<count;i++)
                sum = sum +(*(inputs + j));

            sum = sum/(count - 1);

            sum = qSqrt(sum);

            percent = (mean/flw)*100;

            data1="Mean:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(percent,'f',3)+"% "+QString::number(mean,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);

            percent = (sum/flw)*100;

            data1="SD  :";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(percent,'f',3)+"% "+QString::number(sum,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);

            percent = (min/flw)*100;

            data1="Min :";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(percent,'f',3)+"% "+QString::number(min,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);

            percent = (max/flw)*100;


            data1="Max :";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(percent,'f',3)+"% "+QString::number(max,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);

            percent = (diff/flw)*100;

            data1="Diff:";
            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(percent,'f',3)+"% "+QString::number(diff,'f',3)+"g";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1="<T3-: ";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(lt3)+"    "+QString::number(((lt3/count)*100),'f',3)+"%";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1="<T2-: ";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(lt2)+"    "+QString::number(((lt2/count)*100),'f',3)+"%";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1="<T1-: ";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(lt1)+"    "+QString::number(((lt1/count)*100),'f',3)+"%";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1=">T1+: ";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(gt1)+"    "+QString::number(((gt1/count)*100),'f',3)+"%";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1=">T2+: ";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(gt2)+"    "+QString::number(((gt2/count)*100),'f',3)+"%";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);


            data1=">T3+: ";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();
            port->write(str1,data1.length());
            port->write(&tab,1);

            data2=QString::number(gt3)+"    "+QString::number(((gt3/count)*100),'f',3)+"%";
            for(i=0;i<data2.length();i++)
                str2[i]=data2[i].toAscii();
            port->write(str2,data2.length());
            port->write(&new_line,1);
            port->write(&new_line,1);
            port->write(&new_line,1);


            ui->stoptime->setText(QTime::currentTime().toString("h:mm ap"));
            data1=QDate::currentDate().toString("dd/MM/yyyy")+"   "+ui->stoptime->text();

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();

            port->write(str1,data1.length());
            port->write(&new_line,1);
            port->write(&new_line,1);

            data1="OPERATOR SIGN";

            for(i=0;i<data1.length();i++)
                str1[i]=data1[i].toAscii();

            port->write(str1,data1.length());
            port->write(&new_line,1);
            port->write(&new_line,1);
            port->write(&new_line,1);
            port->write(&new_line,1);
            port->write(&new_line,1);
            port->write(&new_line,1);

        }
    }

    ui->batchidcombobox->setCurrentIndex(0);
    ui->activebatchgroup->setDisabled(1);
    ui->endbatch->setDisabled(1);

    count = 1;

    ui->para_1->clear();
    ui->value_1->clear();
    ui->para_2->clear();
    ui->value_2->clear();
    ui->para_3->clear();
    ui->value_3->clear();
    ui->para_4->clear();
    ui->value_4->clear();
    ui->para_5->clear();
    ui->value_5->clear();
    ui->para_6->clear();
    ui->value_6->clear();
    ui->para_7->clear();
    ui->value_7->clear();
    ui->para_8->clear();
    ui->value_8->clear();
    ui->para_9->clear();
    ui->value_9->clear();
    ui->para_10->clear();
    ui->value_10->clear();

    ui->fillweight->clear();
    ui->tareweight->clear();

    ui->tolerance11->clear();
    ui->tolerance21->clear();
    ui->tolerance31->clear();
    ui->tolerance12->clear();
    ui->tolerance22->clear();
    ui->tolerance32->clear();

    ui->stoptime->clear();
    ui->starttime->clear();

    ui->lastweight->clear();
    ui->currentweight->clear();

    last_weight = 0;

    t1=0;
    t2=0;
    t3=0;
    flw = 0;
    T11=0;
    T12=0;
    T21=0;
    T22=0;
    T31=0;
    T32=0;
    min = 0;
    max = 0;
    mean = 0;
    diff = 0;
    total = 0;
    percent = 0;

    lt1 = 0;
    lt2 = 0;
    lt3 = 0;
    gt1 = 0;
    gt2 = 0;
    gt3 = 0;

    ui->weightdisplayedit->clear();
    ui->countedit->clear();

    ui->activebatchgroup->setDisabled(1);
    ui->stopbutton->setDisabled(1);
    ui->startbutton->setDisabled(1);
    ui->countedit->setDisabled(1);
}
