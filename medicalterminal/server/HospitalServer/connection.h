#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
            "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;

    query.exec(QString("create table doctor (id int primary key, "
               "name varchar, password varchar)"));
    query.exec(QString("insert into doctor values(1, '金辉', '123')"));
    query.exec(QString("insert into doctor values(2, 'admin', '123')"));
    query.exec(QString("insert into doctor values(3, '武哥', '666')"));

    query.exec(QString("create table doctorInfo (id int primary key, "
               "name varchar, code varchar, job varchar, room varchar, time varchar, experience varchar, sex varchar)"));
    query.exec(QString("insert into doctorInfo values(1, '金辉', '1001', '主任', '1234', '8', '20年的医疗经验', '男')"));
    query.exec(QString("insert into doctorInfo values(2, 'admin', '2011', '医师', '8342', '8', '5年手术经验', '男')"));
    query.exec(QString("insert into doctorInfo values(3, '武哥', '6668', '院长', '8888', '8', '10年管理经验', '男')"));

    query.exec(QString("create table patientInfo (id int primary key, "
               "name varchar, sex varchar, age varchar, job varchar, inhospitaltime varchar, adderss varchar, allergic varchar, gotohospitaltime varchar, gotohospitalagaintime varchar, patient varchar)"));
    query.exec(QString("insert into patientInfo values(1, '张三', '男', '35', '学生', '2015-7-8', '沈阳', '无', '2016-1-11', '2016-2-1', '无')"));
    query.exec(QString("insert into patientInfo values(2, '李四', '女', '55', '无业', '2015-8-8', '上海', '无', '2015-1-11', '2017-2-1', '无')"));
    query.exec(QString("insert into patientInfo values(3, '王五', '男', '64', '学生', '2014-7-8', '北京', '无', '2016-1-11', '2016-2-1', '无')"));
    query.exec(QString("insert into patientInfo values(4, '赵六', '女', '56', '主席', '2015-7-7', '湖南', '无', '2015-1-11', '2017-5-1', '无')"));


    query.exec(QString("create table recipeInfo (id int primary key, recipe varchar, medicine varchar)"));

    query.exec(QString("insert into recipeInfo values(1, 'a', '何乌首-山药-人参-燕窝')"));
    query.exec(QString("insert into recipeInfo values(2, 'b', '金银花-三七花-胎菊花')"));
    query.exec(QString("insert into recipeInfo values(3, 'c', '云连-乌梅-麦冬-生地-阿胶')"));
    query.exec(QString("insert into recipeInfo values(4, 'd', '连翘-陈皮-青皮-肉桂-好墨-槟榔-牵牛子-三棱-肉豆蒄')"));



    query.exec(QString("create table medicineInfo (id int primary key, medicine varchar, redundant varchar)"));

    query.exec(QString("insert into medicineInfo values(1, '何乌首', '500克')"));
    query.exec(QString("insert into medicineInfo values(2, '山药', '1斤300克')"));
    query.exec(QString("insert into medicineInfo values(3, '人参', '200克')"));
    query.exec(QString("insert into medicineInfo values(4, '燕窝', '600克')"));

    query.exec(QString("insert into medicineInfo values(5, '金银花', '2斤400克')"));
    query.exec(QString("insert into medicineInfo values(6, '三七花', '500克')"));
    query.exec(QString("insert into medicineInfo values(7, '胎菊花', '1斤400克')"));

    query.exec(QString("insert into medicineInfo values(8, '云连', '530克')"));
    query.exec(QString("insert into medicineInfo values(9, '乌梅', '1斤310克')"));
    query.exec(QString("insert into medicineInfo values(10, '麦冬', '230克')"));
    query.exec(QString("insert into medicineInfo values(11, '生地', '300克')"));
    query.exec(QString("insert into medicineInfo values(12, '阿胶', '600克')"));

    query.exec(QString("insert into medicineInfo values(13, '连翘', '560克')"));
    query.exec(QString("insert into medicineInfo values(14, '陈皮', '1斤300克')"));
    query.exec(QString("insert into medicineInfo values(15, '青皮', '204克')"));
    query.exec(QString("insert into medicineInfo values(16, '肉桂', '620克')"));
    query.exec(QString("insert into medicineInfo values(17, '好墨', '500克')"));
    query.exec(QString("insert into medicineInfo values(18, '槟榔', '5斤300克')"));
    query.exec(QString("insert into medicineInfo values(19, '牵牛子', '250克')"));
    query.exec(QString("insert into medicineInfo values(20, '三棱', '200克')"));
    query.exec(QString("insert into medicineInfo values(21, '肉豆蒄', '500克')"));


    query.exec(QString("create table recorddate (name varchar, date varchar)"));




    return true;
}

#endif // CONNECTION_H
