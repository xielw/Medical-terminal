#include "alarmclock.h"
#include "ui_alarmclock.h"
#include <QLCDNumber>
#include <QTimer>
#include <QWidget>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<QMenu>
#include<QMenuBar>
#include<QMenuItem>
AlarmClock::AlarmClock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmClock)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);


    ui->leftLcdNumber->setDigitCount(2);
    ui->rightLcdNumber->setDigitCount(2);
    timer = new QTimer(this);
    stopTimer = new QTimer(this);

    lCount = 0;
    rCount = 0;

    QMenu *bellTypeMenu = new QMenu(ui->selectBellButton);
    longBell =  bellTypeMenu->addAction("长鸣");
    middleBell =  bellTypeMenu->addAction("中鸣");
    shortBell =  bellTypeMenu->addAction("短鸣");
    longBell->setCheckable(true);
    middleBell->setCheckable(true);
    shortBell->setCheckable(true);
    ui->selectBellButton->setMenu(bellTypeMenu);
    QActionGroup *bellActionGroup = new QActionGroup(this);
    bellActionGroup->addAction(longBell);
    bellActionGroup->addAction(middleBell);
    bellActionGroup->addAction(shortBell);
    connect(longBell,SIGNAL(triggered(bool)),this,SLOT(selectBellType()));
    connect(middleBell,SIGNAL(triggered(bool)),this,SLOT(selectBellType()));
    connect(shortBell,SIGNAL(triggered(bool)),this,SLOT(selectBellType()));

    QMenu *repetitiveNumberMenu = new QMenu(ui->repetitionNumberButton);
    repetitiveThree =  repetitiveNumberMenu->addAction("3次");
    repetitiveTwo =  repetitiveNumberMenu->addAction("2次");
    repetitiveOne =  repetitiveNumberMenu->addAction("1次");
    repetitiveThree->setCheckable(true);
    repetitiveTwo->setCheckable(true);
    repetitiveOne->setCheckable(true);
    ui->repetitionNumberButton->setMenu(repetitiveNumberMenu);
    QActionGroup *repetitionNumberActionGroup = new QActionGroup(this);
    repetitionNumberActionGroup->addAction(repetitiveThree);
    repetitionNumberActionGroup->addAction(repetitiveTwo);
    repetitionNumberActionGroup->addAction(repetitiveOne);
    connect(repetitiveThree,SIGNAL(triggered(bool)),this,SLOT(selectrepetitiveNumber()));
    connect(repetitiveTwo,SIGNAL(triggered(bool)),this,SLOT(selectrepetitiveNumber()));
    connect(repetitiveOne,SIGNAL(triggered(bool)),this,SLOT(selectrepetitiveNumber()));
}

AlarmClock::~AlarmClock()
{
    delete ui;
}

void AlarmClock::on_lAddButton_clicked()
{
    ui->lSubButton->setEnabled(true);
    ui->leftLcdNumber->display(++lCount);

}

void AlarmClock::on_lSubButton_clicked()
{
    if(lCount == 0)
        ui->lSubButton->setEnabled(false);
    ui->leftLcdNumber->display(--lCount);
}

void AlarmClock::on_rAddButton_clicked()
{
      ui->rSubButton->setEnabled(true);
    if(rCount == 59)
        rCount = 0;
    ui->rightLcdNumber->display(++rCount);
}

void AlarmClock::on_rSubButton_clicked()
{
    if(rCount == 0)
        ui->rSubButton->setEnabled(false);
    ui->rightLcdNumber->display(--rCount);
}

void AlarmClock::on_setAlarmButton_clicked()
{

    hValue = ui->leftLcdNumber->value();
    mValue = ui->rightLcdNumber->value();


    int msec = (hValue*60+mValue)*60*1000;
    connect(timer, SIGNAL(timeout()), this, SLOT(startAlarmClock()));

    if(msec !=0)
         timer->start(msec);
}


void AlarmClock::on_cancleAlarmButton_clicked()
{
    timer->disconnect();
}



void AlarmClock::on_backButton_clicked()
{
    this->close();
    pre->show();
}

void AlarmClock::startAlarmClock()
{


    connect(stopTimer, SIGNAL(timeout()), this, SLOT(stopAlarmClock()));

        openBuzzer();
        if(bellType == tr("长鸣")){
            stopTimer->start(5*1000);
        }else if (bellType == tr("中鸣")) {
              stopTimer->start(3*1000);
        }else {
              stopTimer->start(1*1000);
        }




}

void AlarmClock::selectBellType()
{
    bellType = tr("短鸣");
    if(longBell->isChecked()){
        bellType =   longBell->text();
    }
    if(middleBell->isChecked()){
        bellType =   middleBell->text();
    }

    if(shortBell->isChecked()){
        bellType =   shortBell->text();
    }

}

void AlarmClock::selectrepetitiveNumber()
{
    repetitionNumbe = tr("1次");
    if(repetitiveThree->isChecked()){
        repetitionNumbe =   repetitiveThree->text().toInt();
    }
    if(repetitiveTwo->isChecked()){
        repetitionNumbe =   repetitiveTwo->text().toInt();
    }

    if(repetitiveOne->isChecked()){
        repetitionNumbe =   repetitiveOne->text().toInt();
    }
}

void AlarmClock::stopAlarmClock()
{
    timer->disconnect();
    closeBuzzer();
    stopTimer->disconnect();
}

void AlarmClock::openBuzzer()
{
    fd = ::open("/dev/pwm",0);
       if(fd < 0)
       {
           perror("open pwm error");
           exit(1);
       }
       ioctl(fd, 1, 1000);//设置频率
}

void AlarmClock::closeBuzzer()
{
    if(fd >= 0)
        {
            ioctl(fd, 0);

            ::close(fd);

            fd = -1;
        }
}

void AlarmClock::setPre(QWidget *pre)
{
    this->pre = pre;
}
