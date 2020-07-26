#include <QApplication>
#include <QWidget>
#include <QKeySequence>
#include <QMainWindow>
#include <qtermwidget5/qtermwidget.h>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QMainWindow *mainWindow = new QMainWindow();

    QTermWidget *console = new QTermWidget();

    mainWindow->resize(250, 150);
    mainWindow->setWindowTitle("Segia");

    mainWindow->setCentralWidget(console);

    mainWindow->show();

    return app.exec();
}