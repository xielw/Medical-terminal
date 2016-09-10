#ifndef FLOORMAP_H
#define FLOORMAP_H

#include <QWidget>

class FloorMap : public QWidget
{
    Q_OBJECT
public:
    explicit FloorMap(QWidget *parent = 0);
    void setFloor_Room(QString floor,QString room);
signals:


public slots:

private:
    QString floor;
    QString room;

};

#endif // FLOORMAP_H
