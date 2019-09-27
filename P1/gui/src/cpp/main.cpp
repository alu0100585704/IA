#include "mainwindow.h"
#include <QApplication>
#include <aboutdialog.hpp>
int main(int argc, char *argv[])
{
    //Modo grafico
    QApplication a(argc, argv);
    MainWindow w;
    AboutDialog aboutDialog;
    aboutDialog.exec();
    w.show();

    a.exec();
    return 0;

}
