#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
#include <QLabel>
#include<son.h>
#include<QtNetwork>
#include<key.h>
#include<QLineEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void writeData();
     bool eventFilter(QObject *target,QEvent *event);
private:
    Ui::MainWindow *ui;
    QTcpSocket *client;
    son *s;
    QString loginData;
    QString loginResponed;
    Key *im;
    QLineEdit *as;
private slots:
    void showbutton();
    void readMessage();
    void spendMessage();
    void setText(QString);

private:
    void addNamesToNameCombox();

};

#endif // MAINWINDOW_H
