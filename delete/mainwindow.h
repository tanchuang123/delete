#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void deleteExe();
private:
    Ui::MainWindow *ui;
    int j=0;
    int add=0;
    QString cutStr;
    QString needStrPath;
};

#endif // MAINWINDOW_H
