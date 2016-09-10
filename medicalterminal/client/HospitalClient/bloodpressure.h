#ifndef BLOODPRESSURE_H
#define BLOODPRESSURE_H

#include <QDialog>
#include<QTimer>
namespace Ui {
class BloodPressure;
}

class BloodPressure : public QDialog
{
    Q_OBJECT
    
public:
    explicit BloodPressure(QWidget *parent = 0);
    ~BloodPressure();
    void setPre(QWidget *parent);

    void showBloodPressure(QString data);
    
private slots:
    void on_registerButton_clicked();

    void on_testStopButton_clicked();

    void on_pushButton_clicked();

    int openADC();
private:
    Ui::BloodPressure *ui;
    QWidget *pre;
    //QTcpSocket *client;

    int fd;
    QTimer *timer;
    int flag;
};

#endif // BLOODPRESSURE_H
