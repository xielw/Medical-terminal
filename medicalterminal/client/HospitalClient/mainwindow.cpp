#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string.h>
#include<QMessageBox>
#include<QtNetwork>
#include<QtNetworUtils.h>
#include<key.h>
#include<QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      setWindowFlags(Qt::Tool|Qt::FramelessWindowHint);
      QPixmap pixmap("://image/playerground.jpg");
      QPalette palette;
      palette.setBrush(backgroundRole(), QBrush(pixmap));
      this->setPalette(palette);

//    QPixmap pixmap("E:/MyMusicPlayer/image/playerbackground.png");
//    QPalette palette;
//    palette.setBrush(backgroundRole(), QBrush(pixmap));
//    this->setPalette(palette);

    loginData = "loginName";
    im = new Key(this);

    //QPoint point_now=mapToGlobal(geometry().bottomLeft());
    //QPoint point_parent=mapToGlobal(QPoint(0,0));
    //im->setGeometry(point_parent.x(),point_now.y(),240,240);

    ui->setupUi(this);
    setMaximumWidth(320);
    setMaximumHeight(240);\
    ui->passwordLineEdit->installEventFilter(this);
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(showbutton()));
    connect(ui->cancleButton,SIGNAL(clicked()),this,SLOT(close()));


    client = new QTcpSocket(this);
    connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(client,SIGNAL(connected()),this,SLOT(spendMessage()));
    client->abort();
    client->connectToHost(getIp(),getPort());

    QObject::connect(im,SIGNAL(setvalue(QString)),this,SLOT(setText(QString)));

}

MainWindow::~MainWindow()
{


}
bool MainWindow::eventFilter(QObject *target, QEvent *event){
    if((ui->passwordLineEdit==target) &&event->type()==QEvent::MouseButtonPress){
        as=(QLineEdit*)target;
        im->show();
    }
    return QObject::eventFilter(target,event);
}
void MainWindow::showbutton(){
    QString name = ui->nameComboBox->currentText();
    QString password = ui->passwordLineEdit->text();
    QString flag = "login";
    loginData = flag + "-" + name + "-" + password;
    spendMessage();
}

void MainWindow::writeData()
{

    client->write(loginData.toUtf8());

}

void MainWindow::readMessage()
{
    loginResponed =  client->readAll();
    QStringList lists = loginResponed.split("-");

    QString res = "success";
    if(lists.at(0) == "loginNames"){
        addNamesToNameCombox();
    }else if(loginResponed == res)
    {   s=new son;

        s->setName(ui->nameComboBox->currentText());
        s->show();
        this->close();
    }
    else
        QMessageBox::warning(this,0,tr("账号或密码错误"),QMessageBox::Ok);

}

void MainWindow::spendMessage()
{
    writeData();
}

void MainWindow::setText(QString s)
{
    as->setText(s);
}

void MainWindow::addNamesToNameCombox()
{
      QStringList lists = loginResponed.split("-");
      int i = 1;
      for(; i < lists.size(); i++){
          ui->nameComboBox->addItem(lists.at(i));
      }
}


