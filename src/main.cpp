
#include "../include/mainWindow.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow w;

    w.LoadCss(&app);
    w.show();
    return app.exec();
}