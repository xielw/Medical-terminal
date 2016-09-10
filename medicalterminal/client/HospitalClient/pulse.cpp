#include "pulse.h"
#include "ui_pulse.h"
#include<QDateTime>
#include<QPixmap>
#include<QIcon>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>
#include<stdio.h>
#include<QTimer>


Pulse::Pulse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pulse)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
    this->setWindowFlags(Qt::FramelessWindowHint);//去除边框
    date = new QDateTime(QDateTime::currentDateTime());
    QString dateString = date->toString("yyyy年MM月dd日");
    QString ap = date->toString("ap");
    ap = (ap == tr("am") ? tr("上午") : tr("下午"));
    QString timeString = ap + date->toString("hh时mm分");
    ui->dateLabel->setText(dateString);
    ui->timeLabel->setText(timeString);
    QPixmap pix("://image/cancel_red.png");
    pix.scaled(31,31);
    QIcon icon(pix);
    ui->pushButton->setIcon(icon);
    ui->pushButton->setFlat(true);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(openADC()));
    flag = 0;

}

Pulse::~Pulse()
{
    delete ui;
}

void Pulse::setpre(QWidget *parent)
{
    pre = parent;
}

void Pulse::showPulse(QString data)
{
    int pulseValue = data.toInt() / 8;
    ui->numberLabel->setText(QString::number(pulseValue));

}

void Pulse::on_pushButton_clicked()
{
    close();
    pre->show();
}

int Pulse::openADC()
{

    fd = ::open("dev/adc",0);
    if(fd < 0){
        qDebug("open(/dev/adc)failed....\n");
        return 0;
    }

    char buf[32];
    bzero(buf,32);
    if(read(fd,buf,32) < 0){
         qDebug("failed to read buf\n");
         return 0;
    }

    qDebug("ADCValue = %s",buf);
    showPulse(QString::fromUtf8(buf));
    return 1;

}

void Pulse::on_testStopButton_clicked()
{
    if(flag == 0){
        timer->start(1000);
        flag = 1;
    }else {
        timer->stop();
        flag = 0;
    }
}
