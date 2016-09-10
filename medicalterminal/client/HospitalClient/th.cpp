#include "th.h"
#include "ui_th.h"

#include<time.h>
#include<math.h>

TH::TH(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TH)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
    pre = parent;
    srand((int)time(NULL));//随机数种子
   int t =  rand()%21+20;  //产生随机数
   int h = rand()%21+20;
   QString::number(t);    //整型转化字符串
   QString::number(h);

   ui->temperatureLineEdit->setText(QString::number(t));  //设置文本值
   ui->humidityLineEdit->setText(QString::number(h));

}

TH::~TH()
{
    delete ui;
}

void TH::on_backButton_clicked()
{
    this->close();
    pre->show();
}
