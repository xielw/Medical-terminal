#include "data.h"
#include "ui_data.h"
#include<QTimeEdit>
#include<QCalendarWidget>
Data::Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);

    
    ui->timeEdit->setTime(QTime::currentTime());
//    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
//    ui->dateTimeEdit->setDisplayFormat(tr("ap h:m"));
//    ui->timeEdit->setMaximumDate(QDate::currentDate().addDays(-365));
//    ui->timeEdit->setMaximumDate(QDate::currentDate().addDays(365));
   ui->timeEdit->setDisplayFormat("ap h:m");

   ui->calendarWidget->setSelectedDate(QDate::currentDate());
}

void Data::setPre(QWidget *parent)
{
    pre = parent;

}

Data::~Data()
{
    delete ui;
}

void Data::on_pushButton_clicked()
{
    this->close();
    pre->show();
}
