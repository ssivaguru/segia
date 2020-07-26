#include <QApplication>
#include <QWidget>
#include <QKeySequence>
#include <QMainWindow>
#include <qtermwidget5/qtermwidget.h>
#include <QMenuBar>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QMainWindow *mainWindow = new QMainWindow();

    QTermWidget *console = new QTermWidget();

    QMenuBar *menuBar = new QMenuBar(mainWindow);
    QMenu *actionsMenu = new QMenu(QStringLiteral("Actions"), menuBar);
    menuBar->addMenu(actionsMenu);
    actionsMenu->addAction(QStringLiteral("Find..."), console, &QTermWidget::toggleShowSearchBar,
                           QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_F));
    actionsMenu->addAction(QStringLiteral("Copy"), console, &QTermWidget::copyClipboard,
                           QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_C));
    actionsMenu->addAction(QStringLiteral("Paste"), console, &QTermWidget::pasteClipboard,
                           QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_V));
    actionsMenu->addAction(QStringLiteral("About Qt"), &app, &QApplication::aboutQt);
    mainWindow->setMenuBar(menuBar);

    mainWindow->resize(600, 400);
    mainWindow->setWindowTitle("Segia");

    mainWindow->setCentralWidget(console);

    QObject::connect(console, &QTermWidget::finished, mainWindow, &QMainWindow::close);

    //mainWindow->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    mainWindow->show();

    return app.exec();
}