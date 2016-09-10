#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include <QWidget>
#include<QTimer>
#include<QMenu>
#include<QMenuBar>
#include<QMenuItem>
namespace Ui {
class AlarmClock;
}

class AlarmClock : public QWidget
{
    Q_OBJECT
    
public:
    explicit AlarmClock(QWidget *parent = 0);
    ~AlarmClock();

    void setPre(QWidget *pre);
    
private slots:
    void on_lAddButton_clicked();

    void on_lSubButton_clicked();

    void on_rAddButton_clicked();

    void on_rSubButton_clicked();

    void on_setAlarmButton_clicked();

    void on_cancleAlarmButton_clicked();

    void on_backButton_clicked();

    void startAlarmClock();
    void selectBellType();
    void selectrepetitiveNumber();
    void stopAlarmClock();
    void openBuzzer();
    void closeBuzzer();
private:
    Ui::AlarmClock *ui;
    int lCount;
    int rCount;
    int hValue;
    int mValue;
    QWidget *pre;

    QTimer *timer;
    QTimer *stopTimer;
    QAction *longBell;
    QAction *middleBell;
    QAction *shortBell;


    QAction *repetitiveOne;
    QAction *repetitiveTwo;
    QAction *repetitiveThree;
    QString   repetitionNumbe;
    QString bellType;

    int fd;
};

#endif // ALARMCLOCK_H
