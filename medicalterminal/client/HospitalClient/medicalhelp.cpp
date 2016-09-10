#include "medicalhelp.h"
#include "ui_medicalhelp.h"
#include "QtNetworUtils.h"
#include<QLineEdit>
#include<QDebug>
#include<QStringList>
#include<QLCDNumber>
MedicalHelp::MedicalHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MedicalHelp)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
    pre = parent;
    //ui->push->setEnabled(false);
    //ui->push->setDisabled(true);

    im = new Key(this);
    ui->recipeLineEdit->installEventFilter(this);
    connect(im,SIGNAL(setvalue(QString)),this,SLOT(setText(QString)));

    client = new QTcpSocket(this);
    connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(client,SIGNAL(connected()),this,SLOT(spendMessage()));

    connect(ui->recipeLineEdit,SIGNAL(textChanged(QString)),this,SLOT(showRecipe(QString)));
    connect(ui->medicineComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(showSelectedMedicineRedundant()));
}

MedicalHelp::~MedicalHelp()
{
    delete ui;
}

void MedicalHelp::writeData()
{
     client->write(SendMsg.toUtf8());

}

void MedicalHelp::on_backButton_clicked()
{
    pre->show();
    this->close();
}

void MedicalHelp::setText(QString s)
{
    as->setText(s);
}

void MedicalHelp::readMessage()
{
       receiptMsg =  client->readAll();
       QStringList medicines = receiptMsg.split("-");
       if(medicines.at(0) == "recipe"){
           addItemToNameComBox();
       }else {

          ui->redundantLineEdit->setText(receiptMsg);
       }
}

void MedicalHelp::addItemToNameComBox()
{
  ui->medicineComboBox->clear();
  QStringList medicines =  receiptMsg.split("-");
  int i = 1;
  for(; i < medicines.size(); i++)
      ui->medicineComboBox->addItem(medicines.at(i));
}

void MedicalHelp::showSelectedMedicineRedundant()
{
    QString medicine = ui->medicineComboBox->currentText();

    QString flag = "medicine";
    SendMsg = flag + tr("-") + medicine;
    writeData();

}

void MedicalHelp::spendMessage()
{
    writeData();
}

void MedicalHelp::showRecipe(QString text)
{
    ui->redundantLineEdit->setText("");
    client->abort();
    client->connectToHost(getIp(),getPort());

    QString flag = "recipe";
    SendMsg = flag + tr("-") + text;
}

bool MedicalHelp::eventFilter(QObject *target, QEvent *event){
    if((ui->recipeLineEdit==target) &&event->type()==QEvent::MouseButtonPress){
        as=(QLineEdit*)target;
        im->show();
    }
    return QObject::eventFilter(target,event);
}
