#include <QtGui>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Weigh Bridge Indicator");
    w.showMaximized();
    
    return a.exec();
}
