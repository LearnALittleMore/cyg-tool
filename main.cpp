#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Widget mainWindow;
    mainWindow.show();

    return app.exec();
}
