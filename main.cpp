#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Set the text of the entire application to white
    a.setStyleSheet(
        "QWidget {"
        "   color: white;"  // Set text color to white
        "   background-color: #2E2E2E;"  // Optional: Set a dark background
        "}"
        );

    MainWindow w;
    w.show();

    return a.exec();
}
