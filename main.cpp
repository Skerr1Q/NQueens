#include "mainwindow.h"
#include <board.h>

#include <QApplication>
#include <QTextEdit>
#include <QSpinBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
