#include "bloodpressure.h"
#include "ui_bloodpressure.h"
#include<sys/types.h>

#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>
#include<stdio.h>
#include<QTimer>

BloodPressure::BloodPressure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BloodPressure)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);

   this->setWindowFlags(Qt::FramelessWindowHint);//去除边框


    ui->pushButton->setIcon(QPixmap("://image/cancel_red.png"));
    ui->pushButton->setIconSize(QSize(31,31));
   ui->pushButton->setFlat(true);


   timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(openADC()));
   flag = 0;
}

BloodPressure::~BloodPressure()
{
    delete ui;
}

void BloodPressure::setPre(QWidget *parent)
{
    pre = parent;
}

void BloodPressure::showBloodPressure(QString data)
{


    int pressureValue = data.toInt();


    ui->maxLineEdit->setText(QString::number(pressureValue / 5 + 15));
    ui->minLineEdit->setText(QString::number(pressureValue / 5 - 15));


}

void BloodPressure::on_registerButton_clicked()
{
    
}

void BloodPressure::on_testStopButton_clicked()
{

    if(flag == 0){
        timer->start(1000);
        flag = 1;
    }else {
        timer->stop();
        flag = 0;
    }

}

void BloodPressure::on_pushButton_clicked()
{
    close();
    pre->show();
}

int BloodPressure::openADC()
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
    showBloodPressure(QString::fromUtf8(buf));
    return 1;
}
