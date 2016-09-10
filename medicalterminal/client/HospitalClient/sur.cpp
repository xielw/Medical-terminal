#include "sur.h"
#include "ui_sur.h"
#include<QMessageBox>
#include<QComboBox>
#include<QDebug>
#include "floormap.h"
sur::sur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sur)
{
    ui->setupUi(this);
    setWindowTitle("医院环境");
   setWindowIcon(QIcon("://image/close_hover.png"));


   QPixmap pixmap("://image/playerground.jpg");
   QPalette palette;
   palette.setBrush(backgroundRole(), QBrush(pixmap));
   this->setPalette(palette);

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(bac()));
    pre=parent;



}



sur::~sur()
{
    delete ui;
}
void sur::bac(){
    this->close();
    pre->show();
}






void sur::on_searchButton_clicked()
{
    QString floor = ui->floorComboBox->currentText();
    QString room = ui->roomComboBox->currentText();

   /* floorMap = new FloorMap(this);
    floorMap->setFloor_Room(floor,room);
    floorMap->show();*/
    test *t=new test(floor,room);
    t->setPre(this);
    t->show();
    hide();

}
