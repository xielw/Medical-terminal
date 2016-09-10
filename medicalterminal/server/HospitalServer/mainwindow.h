#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtNetwork>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlRecord>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
private:
    QString queryLoginNames();
    QString dealLogin();
    QString dealDoctorInfos();
    QString queryDoctorNames();
    QString deleteSeletedDoctor();
    QString querySickNames();
    QString dealSickInfos();
    QString deleteSeletedSick();
    QString queryRecipeInfos();
    QString queryMedicineInfos();
    QString dealCardInfo(QString msg);
    void insertDateOfCard();
private slots:
    void acceptConnection();
    void readData();
private:
    Ui::MainWindow *ui;
    QTcpServer *server;
    QTcpSocket *connectClient;
    QSqlDatabase db;
    QSqlQuery query;
    QString sql;
    QString spendMsg;

};

#endif // MAINWINDOW_H
