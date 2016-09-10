#ifndef PULSE_H
#define PULSE_H

#include <QDialog>
#include<QDateTime>
#include<QTimer>
namespace Ui {
class Pulse;
}

class Pulse : public QDialog
{
    Q_OBJECT

public:
    explicit Pulse(QWidget *parent = 0);
    ~Pulse();
    void setpre(QWidget *parent);

    void showPulse(QString data);
private slots:
    void on_pushButton_clicked();

    int openADC();
    void on_testStopButton_clicked();

private:
    Ui::Pulse *ui;
    QWidget *pre;
    QDateTime *date;

    int fd;
    QTimer *timer;
    int flag;

};

#endif // PULSE_H
