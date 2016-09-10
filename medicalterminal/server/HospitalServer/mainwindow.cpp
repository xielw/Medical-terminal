#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlRecord>
#include<QStringList>
#include<QMessageBox>
#include<QtNetworkUtils.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    while(!server->isListening()&&!server->listen(QHostAddress::Any,setPort())){
       QString message =  server->errorString();
       ui->textEdit->setText("连接失败" + message);
       return ;
    }

    connect(server,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}

QString MainWindow::dealLogin()
{
    QString loginState = "false";
    QSqlQuery query(sql);
    int flag = 0;
    if(query.isActive()){
        while(query.next()){
                ++flag;
                break;
        }
    }
    if(flag > 0)
         loginState = "success";
    else
         loginState = "false";
    return loginState;
}

QString MainWindow::dealDoctorInfos()
{

    QString msg = "";
        QSqlQuery query(sql);
        if(query.isActive()){

            while(query.next()){

                msg = query.value(1).toString() + tr("-")+
                query.value(2).toString() + tr("-") +
                query.value(3).toString() + tr("-") +
                query.value(4).toString() + tr("-") +
                query.value(5).toString() + tr("-") +
                query.value(6).toString() + tr("-") +
                query.value(7).toString();

                }

            }
    return msg;
}

QString MainWindow::queryDoctorNames()
{

    QString msg = "names";
        QSqlQuery query(sql);
        if(query.isActive()){
           while(query.next()){
                msg = msg +tr("-")+query.value(1).toString();

                }
            }

        return msg;
}

QString MainWindow::deleteSeletedDoctor()
{
    QSqlQuery query;
    QString msg = "";
    query.exec(sql);
    sql = "select * from doctorInfo";
    msg = queryDoctorNames();
    return msg;
}

QString MainWindow::querySickNames()
{

    QString msg = "sicks";
        QSqlQuery query(sql);
        if(query.isActive()){
           while(query.next()){
                msg = msg +tr("-")+query.value(1).toString();

                }
            }
        return msg;
}

QString MainWindow::dealSickInfos()
{
    QString msg = "";
        QSqlQuery query(sql);
        if(query.isActive()){

            while(query.next()){

                msg = query.value(1).toString() + tr("+")+
                query.value(2).toString() + tr("+") +
                query.value(3).toString() + tr("+") +
                query.value(4).toString() + tr("+") +
                query.value(5).toString() + tr("+") +
                query.value(6).toString() + tr("+") +
                query.value(7).toString() + tr("+") +
                query.value(8).toString() + tr("+") +
                query.value(9).toString() + tr("+") +
                query.value(10).toString();

                }

            }
        return msg;
}

QString MainWindow::deleteSeletedSick()
{
    QSqlQuery query;
    QString msg = "";
    query.exec(sql);
    sql = "select * from patientInfo";
    msg = querySickNames();
    return msg;
}

QString MainWindow::queryRecipeInfos()
{

    QString msg = "recipe";
        QSqlQuery query(sql);
        if(query.isActive()){
           while(query.next()){
                msg = msg +tr("-")+query.value(2).toString();
                }
            }
        return msg;

}

QString MainWindow::queryMedicineInfos()
{
    QString msg = "";
    QSqlQuery query(sql);
    if(query.next()){
       msg = query.value(0).toString();
    }
    return msg;
}

QString MainWindow::dealCardInfo(QString msg)
{
    QStringList lists = msg.split("-");
    QString name = lists.at(1);
    QString date = lists.at(2);
    QString sql = tr("insert into recorddate values ('") +name + tr("','") + date + tr("')");
    qDebug()<<sql+tr("-------insertDateOfCard--------");
    return sql;
}

void MainWindow::insertDateOfCard()
{
    qDebug()<<sql+tr("-------dealCardInfo--------");
       QSqlQuery query;
       query.exec(sql);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::queryLoginNames()
{
    QString msg = "loginNames";
        QSqlQuery query(sql);
        if(query.isActive()){
           while(query.next()){
                msg = msg +tr("-")+query.value(1).toString();
                }
            }
        return msg;

}

void MainWindow::acceptConnection()
{
    connectClient = server->nextPendingConnection();
    connect(connectClient,SIGNAL(readyRead()),this,SLOT(readData()));


}

void MainWindow::readData()
{

    QString data = connectClient->readAll();
    qDebug()<<data;
    QStringList lists = data.split("-");
    ui->textEdit->setText(data);
    QString flag = lists.at(0);
    if(flag == "loginName"){
        sql = "select * from doctor";
        spendMsg = queryLoginNames();
    }else if(flag == "login"){
        sql = "select * from doctor where name = '" + lists.at(1) + "' and " + "password =  '"+ lists.at(2)+ "'";
        spendMsg = dealLogin();

    }else if(flag == "doctorinfos"){
        sql = "select * from doctorInfo where name = '" +lists.at(1) + "'";
        spendMsg = dealDoctorInfos();
    }else if(flag == "names"){
        sql = "select * from doctorInfo";
        spendMsg = queryDoctorNames();
    }else if(flag == "infos"){
        sql = "select * from doctorInfo where name = '" +lists.at(1) + "'";
        spendMsg = dealDoctorInfos();
    }else if(flag == "deleteDoctor"){
        sql = "delete from doctorInfo where name = '" + lists.at(1) + "'";
        spendMsg = deleteSeletedDoctor();
    }else if(flag == "sicks"){
        sql = "select * from patientInfo";
        spendMsg = querySickNames();
    }else if(flag == "sickInfos"){
         sql = "select * from patientInfo where name = '" +lists.at(1) + "'";
         spendMsg = dealSickInfos();
    }else if(flag == "deleteSick"){
         sql = "delete from patientInfo where name = '" + lists.at(1) + "'";
         spendMsg = deleteSeletedSick();
    }else if (flag == "recipe") {
        sql = "select * from recipeInfo where recipe = '"+ lists.at(1) + "'";
        spendMsg = queryRecipeInfos();
    }else if(flag == "medicine"){
        sql = "select redundant from medicineInfo where medicine = '"+ lists.at(1) + "'";
        spendMsg = queryMedicineInfos();
    }else if ("card" == flag) {
        sql = dealCardInfo(data);
           qDebug()<<sql+tr("-------readData--------");
        insertDateOfCard();
    }
    connectClient->write(spendMsg.toUtf8());
}
