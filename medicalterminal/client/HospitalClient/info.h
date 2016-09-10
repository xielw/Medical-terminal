#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include<QtNetwork>
namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT
    
public:
    explicit info(QWidget *parent = 0);
    ~info();
    void writeData();
    void addItemToNameComBox();
    void showSelectedDoctorInfos();

private:
    Ui::info *ui;
     QWidget*pre;
     QTcpSocket *client;
     QString responedMsg;
private slots:
    void close1();
    void on_enterButton_clicked();
    void on_deleteButton_clicked();
    void readMessage();
    void spendMessage();
    void clearUi();

};

#endif // INFO_H
