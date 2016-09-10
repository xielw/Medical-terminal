#include "son.h"
#include "ui_son.h"
#include<QMessageBox>
#include<QDebug>
#include<QtNetwork>
son::son(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::son)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::Tool|Qt::FramelessWindowHint);
    setWindowTitle("欢迎来到海尔医院");
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(dom()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(su()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(showinfo()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(sim()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(tec()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(tol()));



}

void son::setName(QString name)
{
    this->name = name;
    qDebug()<<name<<"";
}

son::~son()
{
delete ui;
}
void son::showinfo(){


    infor=new info(this);
    infor->show();
    hide();

}

void son::su(){
    sut=new sur(this);
    sut->show();
    hide();

}
void son::dom(){

    dot=new dor(this);
    dot->setName(name);
    dot->show();

    hide();
}
void son::sim(){
    sic=new sick(this);
    sic->show();

    hide();
}
void son::tec(){
    tes=new ces(this);
    tes->show();
    hide();
}
void son::tol(){
    too=new tool(this);
    too->show();
    hide();
}


