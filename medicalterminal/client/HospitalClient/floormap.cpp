#include "floormap.h"
#include<QPixmap>
#include<QPalette>
#include <QDebug>
FloorMap::FloorMap(QWidget *parent) :
    QWidget(parent)
{

    setMaximumWidth(320);
    setMaximumHeight(240);


}

void FloorMap::setFloor_Room(QString floor, QString room)
{
    this->floor = floor;
    this->room = room;
    qDebug()<<floor<<room;
   // QString image_path = "E:\\Qt\\HospitalClient\\image\\" + floor + tr("-") + room;
    QString image_path = "://image/A1-1.jpg";
    QPixmap pixmap(image_path);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
}


