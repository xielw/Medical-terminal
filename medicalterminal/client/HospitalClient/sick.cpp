#include "sick.h"
#include "ui_sick.h"
#include<QMessageBox>
#include<QtNetwork>
#include<QtNetworUtils.h>
#include <QStringList>
sick::sick(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sick)
{



    ui->setupUi(this);
     setWindowTitle("患者信息");
     QPixmap pixmap("://image/playerground.jpg");
     QPalette palette;
     palette.setBrush(backgroundRole(), QBrush(pixmap));
     this->setPalette(palette);
     //setWindowIcon(QIcon("E:/MyMusicPlayer/image/close_hover.png"));


     //QPixmap pixmap("E:/MyMusicPlayer/image/playerbackground.png");
     //QPalette palette;
     //palette.setBrush(backgroundRole(), QBrush(pixmap));
     //this->setPalette(palette);
     connect(ui->escButton,SIGNAL(clicked()),this,SLOT(close3()));

     connect(ui->nameComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(clearUi()));
     pre=parent;

     client = new QTcpSocket(this);
     connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
     connect(client,SIGNAL(connected()),this,SLOT(spendMessage()));

     client->abort();
     client->connectToHost(getIp(),getPort());


}

sick::~sick()
{
    delete ui;
}

void sick::writeData()
{
    QString flag = "sicks";
    client->write(flag.toUtf8());


}

void sick::addItemToNameComBox()
{

    ui->nameComboBox->clear();
    QStringList names =  responedMsg.split("-");
    int i = 1;
    for(; i < names.size(); i++)
    ui->nameComboBox->addItem(names.at(i));

}

void sick::showSelectedSickInfos()
{
    QStringList infos =  responedMsg.split("+");
    ui->sexLineEdit->setText(infos.at(1));
    ui->ageLineEdit->setText(infos.at(2));
    ui->jobLineEdit->setText(infos.at(3));
    ui->inHospitalLineEdit->setText(infos.at(4));
    ui->adderssLineEdit->setText(infos.at(5));
    ui->allergicLineEdit->setText(infos.at(6));
    ui->goToHospitalLineEdit->setText(infos.at(7));
    ui->goToHospitalAgainLineEdit->setText(infos.at(8));
    ui->patienttTextEdit->setText(infos.at(9));
}
void sick::close3(){

    this->close();
    pre->show();

}





void sick::on_enterButton_clicked()
{
    QString selectedName = ui->nameComboBox->currentText();
    QString flag = "sickInfos";
    client->write((flag + tr("-") + selectedName).toUtf8());
}

void sick::on_deleteButton_clicked()
{

    QString selectedName = ui->nameComboBox->currentText();
    QString flag = "deleteSick";
    client->write((flag + tr("-") + selectedName).toUtf8());
}

void sick::readMessage()
{
    responedMsg =  client->readAll();
    qDebug()<<responedMsg + tr("---sick--");
    QStringList lists= responedMsg.split("-");
    if(lists.at(0) == "sicks")
       addItemToNameComBox();
    else
        showSelectedSickInfos();
}

void sick::spendMessage()
{
    writeData();
}

void sick::clearUi()
{


    ui->sexLineEdit->setText(tr(""));
    ui->ageLineEdit->setText(tr(""));
    ui->jobLineEdit->setText(tr(""));
    ui->inHospitalLineEdit->setText(tr(""));
    ui->adderssLineEdit->setText(tr(""));
    ui->allergicLineEdit->setText(tr(""));
    ui->goToHospitalLineEdit->setText(tr(""));
    ui->goToHospitalAgainLineEdit->setText(tr(""));
    ui->patienttTextEdit->setText(tr(""));

}
