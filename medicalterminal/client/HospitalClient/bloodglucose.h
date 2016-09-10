#ifndef BLOODGLUCOSE_H
#define BLOODGLUCOSE_H

#include <QDialog>
#include<QDateTime>
#include<QTimer>
namespace Ui {
class BloodGlucose;
}

class BloodGlucose : public QDialog
{
    Q_OBJECT

public:
    explicit BloodGlucose(QWidget *parent = 0);
    ~BloodGlucose();
    void setPre(QWidget *parent);

    void showBloodGlucose(QString data);
private slots:
    void on_pushButton_clicked();

    int openADC();

    void on_testStopButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::BloodGlucose *ui;
    QWidget *pre;
    QDateTime *date;

    int fd;
    QTimer *timer;
    int flag;
};

#endif // BLOODGLUCOSE_H
