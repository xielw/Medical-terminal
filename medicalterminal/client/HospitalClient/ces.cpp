#include "ces.h"
#include "ui_ces.h"
#include<QMessageBox>
#include<bloodpressure.h>
#include<pulse.h>
#include<bloodglucose.h>
ces::ces(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ces)
{
    ui->setupUi(this);
    setWindowTitle("医疗测试");
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);



    connect(ui->backButton,SIGNAL(clicked()),this,SLOT(close5()));
    pre=parent;
}

ces::~ces()
{
    delete ui;
}
void ces::close5(){

    this->close();
    pre->show();

}

void ces::on_bloodPressureButton_clicked()
{
    bp = new BloodPressure;
    bp->setPre(this);
    bp->show();
    hide();

}

void ces::on_bloodGlucoseButton_clicked()
{
    glucose = new BloodGlucose;
    glucose->setPre(this);
    glucose->show();
    hide();
}

void ces::on_pulseButton_clicked()
{
    pulse  = new Pulse;
    pulse->setpre(this);
    pulse->show();
    hide();
}
