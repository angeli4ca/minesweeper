/**
  @brief main function the launches the application
  @author Angelica Patsko
  @date 4/22/2016
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
