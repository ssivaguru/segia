
#ifndef _MAINWINDOW_CPP_
#define _MAINWINDOW_CPP_

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <qtermwidget5/qtermwidget.h>
#include <QApplication>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStatusBar *status;
    QMenuBar *menuBar;
    QTermWidget *console;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool LoadCss(QApplication *app);

private:
    void createMenuBar();
};

#endif