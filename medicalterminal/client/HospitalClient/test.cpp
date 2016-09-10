#include "test.h"
#include "ui_test.h"
#include<QMouseEvent>
test::test(QString floor,QString room,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);


    QString image_path = tr("://image/")+floor+tr("-")+room+tr(".jpg");
    QPixmap pixmap(image_path);
    pixmap.scaled(240,320);
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);//去除边框
    this->setPalette(palette);

}

test::~test()
{
    delete ui;
}

void test::setPre(QWidget *parent)
{
    pre = parent;
}



void test::mouseDoubleClickEvent(QMouseEvent *){

    this->close();
    pre->show();
}
