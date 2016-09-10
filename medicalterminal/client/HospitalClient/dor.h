#ifndef DOR_H
#define DOR_H

#include <QDialog>
#include<QtNetwork>
#include <QWidget>
#include <QTimer>
namespace Ui {
class dor;
}

class dor : public QDialog
{
    Q_OBJECT
    
public:
    explicit dor(QWidget *parent = 0);
    ~dor();
    void setName(QString name);
    void writeData();
    void openBuzzer();
    void closeBuzzer();
private:
    Ui::dor *ui;
    QWidget*pre;
    QString name;
    QTcpSocket *client;
    QString msg;
    QTimer *timer;
    int fd;
private slots:
   void close4();
   void readMessage();
   void spendMessage();
   void on_cardButton_clicked();
   void stopBell();

};

#endif // DOR_H
