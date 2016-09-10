#include "tool.h"
#include "ui_tool.h"
#include <data.h>
#include<QMessageBox>
#include<alarmclock.h>
#include<th.h>
#include<calculator.h>
tool::tool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tool)
{
    ui->setupUi(this);
    setWindowTitle("小工具");
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);



  //  connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(close2()));
    pre=parent;
}

tool::~tool()
{
    delete ui;
}
//void tool::close2(){

//    this->close();

//     pre->show();

//}

void tool::on_calculatorButton_clicked()
{

    cal = new calculator;
    cal->setPre(this);
    cal->show();
    hide();

}

void tool::on_showTimeButton_clicked()
{
    data = new Data;
    data->setPre(this);
    data->show();
    hide();

}

void tool::on_THButton_clicked()
{

    th = new TH(this);
    th->show();
    this->hide();


}

void tool::on_medicalHelpButton_clicked()
{
    helper = new MedicalHelp(this);
    helper->show();
    this->hide();
}



void tool::on_clockButton_clicked()
{

    clock = new AlarmClock;
    clock->setPre(this);
    clock->show();
    this->hide();
}

void tool::on_backButton_clicked()
{
    this->close();
    pre->show();
}
