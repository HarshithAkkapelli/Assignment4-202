#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <bits/stdc++.h>
using namespace std;
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_startGameButton_clicked();
    void gamePlay(string humanChoice);
    void on_rock_clicked();

private:
    Ui::MainWindow *ui;
    string strategy;
    int numRounds;
    int round;
};
#endif // MAINWINDOW_H
