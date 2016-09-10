#include "dor.h"
#include "ui_dor.h"
#include<QMessageBox>
#include <QDebug>
#include<QtNetwork>
#include<QStringList>
#include<QtNetworUtils.h>
#include<QDateTime>
#include <QWidget>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<QTimer>
dor::dor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dor)
{
    ui->setupUi(this);
    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
     setWindowTitle("个人信息");


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(stopBell()));

    connect(ui->backButton,SIGNAL(clicked()),this,SLOT(close4()));
    pre=parent;

    client = new QTcpSocket(this);
    connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(client,SIGNAL(connected()),this,SLOT(spendMessage()));
    client->abort();
    client->connectToHost(getIp(),getPort());
}

dor::~dor()
{
    delete ui;
}

void dor::setName(QString name)
{
    this->name = name;
    qDebug()<<name<<"dor";
}

void dor::writeData()
{

    client->write((tr("doctorinfos")+tr("-")+name).toUtf8()); 
}

void dor::openBuzzer()
{
    fd = ::open("/dev/pwm",0);
       if(fd < 0)
       {
           perror("open pwm error");
           exit(1);
       }
       ioctl(fd, 1, 1000);//设置频率

       qDebug()<<"open the bell";
}

void dor::closeBuzzer()
{                                                         --

    if(fd >= 0)
       {
           ioctl(fd, 0);

           ::close(fd);

           fd = -1;
       }
       qDebug()<<"close the bell";
}

void dor::stopBell()
{
    closeBuzzer();
    timer->disconnect();

}

void dor::on_cardButton_clicked()
{
    QDateTime *date = new QDateTime(QDateTime::currentDateTime());
    QString dateString = date->toString("yyyy/MM/dd hh:mm:ss ap");
    qDebug()<<dateString;
    client->write((tr("card") +tr("-") + name + tr("-") + dateString ).toUtf8());
    timer->start(3000);
    openBuzzer();

}


void dor::close4(){

    this->close();
     pre->show();

}

void dor::readMessage()
{
    msg = client->readAll();
    QStringList lists = msg.split("-");
    ui->nameLabel->setText(lists.at(0));
    ui->codeLabel->setText(lists.at(1));
    ui->jobLabel->setText(lists.at(2));
    ui->roomLabel->setText(lists.at(3));
    ui->timeLabel->setText(lists.at(4));
    ui->experienceLabel->setText(lists.at(5));

}

void dor::spendMessage()
{
     writeData();
}



