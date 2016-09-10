#include "info.h"
#include "ui_info.h"
#include<QMessageBox>
#include<QStringList>
#include<QPixmap>
#include<QPalette>
#include<QtNetworUtils.h>
info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    setWindowTitle("医生信息");
    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
//    setWindowIcon(QIcon("E:/MyMusicPlayer/image/close_hover.png"));


//    QPixmap pixmap("E:/MyMusicPlayer/image/playerbackground.png");
//    QPalette palette;
//    palette.setBrush(backgroundRole(), QBrush(pixmap));
//    this->setPalette(palette);


    client = new QTcpSocket(this);
    connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(client,SIGNAL(connected()),this,SLOT(spendMessage()));

    client->abort();
    client->connectToHost(getIp(),getPort());

    connect(ui->escButton,SIGNAL(clicked()),this,SLOT(close1()));
    pre=parent;
    connect(ui->nameComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(clearUi()));
}

info::~info()
{
    delete ui;
}

void info::writeData()
{
    QString flag = "names";
    client->write(flag.toUtf8());
}

void info::addItemToNameComBox()
{
  ui->nameComboBox->clear();
  QStringList names =  responedMsg.split("-");
  int i = 1;
  for(; i < names.size(); i++)
  ui->nameComboBox->addItem(names.at(i));
}

void info::showSelectedDoctorInfos()
{
    QStringList infos =  responedMsg.split("-");
   ui->jobLineEdit->setText(infos.at(2));
   ui->roomLineEdit->setText(infos.at(3));
   ui->timeLineEdit->setText(infos.at(4));
   ui->experienceTextEdit->setText(infos.at(5));
   ui->sexLineEdit->setText(infos.at(6));

   QString code = infos.at(1);

//   qDebug() << code;
//   QString image_path = tr("/image/")+code+tr(".jpg");
//   QPixmap pixmap(image_path);
//   pixmap.scaled(90,112);
//   QPalette palette;
//   palette.setBrush(backgroundRole(), QBrush(pixmap));
//   ui->imageLabel->setPalette(palette);

   ui->imageLabel->setStyleSheet("background-image: url(:/image/"+code+".jpg);border:none;");

}
void info::close1(){

    this->close();

  pre->show();

}



void info::on_enterButton_clicked()
{
    QString selectedName = ui->nameComboBox->currentText();
    QString flag = "infos";
    client->write((flag + tr("-") + selectedName).toUtf8());
}

void info::on_deleteButton_clicked()
{

    QString selectedName = ui->nameComboBox->currentText();
    QString flag = "deleteDoctor";
    client->write((flag + tr("-") + selectedName).toUtf8());
}



void info::readMessage()
{
     responedMsg =  client->readAll();
     qDebug()<<responedMsg;
     QStringList lists= responedMsg.split("-");
     if(lists.at(0) == "names")
        addItemToNameComBox();
     else
         showSelectedDoctorInfos();
}

void info::spendMessage()
{
    writeData();
}

void info::clearUi()
{
    ui->sexLineEdit->setText("");
    ui->roomLineEdit->setText("");
    ui->timeLineEdit->setText("");
    ui->experienceTextEdit->setText("");
    ui->jobLineEdit->setText("");
  //  ui->imageLabel->setBackgroundRole(0);
}
