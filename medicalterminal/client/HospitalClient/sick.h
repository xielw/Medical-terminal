#ifndef SICK_H
#define SICK_H

#include <QDialog>
#include<QtNetwork>
namespace Ui {
class sick;
}

class sick : public QDialog
{
    Q_OBJECT
    
public:
    explicit sick(QWidget *parent = 0);
    ~sick();
    
private:
    Ui::sick *ui;
    QWidget*pre;
    QTcpSocket *client;
    QString responedMsg;
    void writeData();
    void addItemToNameComBox();
    void showSelectedSickInfos();
private slots:
    void close3();
    void on_enterButton_clicked();
    void on_deleteButton_clicked();
    void readMessage();
    void spendMessage();
    void clearUi();

};

#endif // SICK_H
