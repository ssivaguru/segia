#include "../include/mainWindow.h"
#include <QWidget>
#include <QKeySequence>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QPushButton>
#include <QGridLayout>
#include <QToolButton>
#include <QFile>

#include "param.cpp"

bool MainWindow::LoadCss(QApplication *app)
{
    try
    {
        QFile File("/home/siva/LinuxAgent/agent/source/src/MyGit/segia/css/stylesheet.css");
        File.open(QFile::ReadOnly);
        QString StyleSheet = QLatin1String(File.readAll());
        app->setStyleSheet(StyleSheet);
    }
    catch (int e)
    {
        //have to add a logger
        printf("LoadCss:: error loading css %d", e);
        return false;
    }

    return true;
}

void MainWindow::createMenuBar()
{
    QMenu *actionsMenu = new QMenu(QStringLiteral("Settings"), this->menuBar);
    this->menuBar->addMenu(actionsMenu);
    actionsMenu->addAction(QStringLiteral("Find..."), console, &QTermWidget::toggleShowSearchBar,
                           QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_F));
    actionsMenu->addAction(QStringLiteral("Copy"), console, &QTermWidget::copyClipboard,
                           QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_C));
    actionsMenu->addAction(QStringLiteral("Paste"), console, &QTermWidget::pasteClipboard,
                           QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_V));
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          status(new QStatusBar()),
                                          menuBar(new QMenuBar(nullptr)),
                                          console(new QTermWidget())
{

    QToolButton *toolButton = new QToolButton(nullptr);
    toolButton->setIcon(QIcon("/home/siva/LinuxAgent/agent/source/src/MyGit/segia/icons/settings_btn.png"));
    resize(600, 400);
    setWindowTitle(APPLICATION_NAME);

    this->createMenuBar();
    //setMenuBar(this->menuBar);

    setCentralWidget(console);

    QObject::connect(console, &QTermWidget::finished, this, &QMainWindow::close);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    QWidget *widget = new QWidget();
    QGridLayout *layout = new QGridLayout(widget);
    //layout->addWidget(this->menuBar, 0, 1, 1, 1, Qt::AlignVCenter | Qt::AlignRight);
    layout->addWidget(toolButton, 0, 1, 1, 1, Qt::AlignVCenter | Qt::AlignRight);
    this->status->addWidget(widget, 1);
    setStatusBar(this->status);
}

MainWindow::~MainWindow()
{
}