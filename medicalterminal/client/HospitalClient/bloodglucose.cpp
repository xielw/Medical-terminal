#include "bloodglucose.h"
#include "ui_bloodglucose.h"
#include <QDateTime>
#include<QDebug>
#include<QPixmap>
#include<QIcon>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>
#include<stdio.h>
#include<QTimer>

BloodGlucose::BloodGlucose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BloodGlucose)
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

BloodGlucose::~BloodGlucose()
{
    delete ui;
}

void BloodGlucose::setPre(QWidget *parent)
{
    pre = parent;
}

void BloodGlucose::showBloodGlucose(QString data)
{
    double glucoseValue =  data.toDouble();
    ui->numberLabel->setText(QString::number(glucoseValue / 100.0));


}

void BloodGlucose::on_pushButton_clicked()
{
    close();
    pre->show();
}


int BloodGlucose::openADC()
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
    showBloodGlucose(QString::fromUtf8(buf));
    return 1;
}

void BloodGlucose::on_testStopButton_clicked()
{
    if(flag == 0){
        timer->start(1000);
        flag = 1;
    }else {
        timer->stop();
        flag = 0;
    }
}

void BloodGlucose::on_registerButton_clicked()
{

}
