#ifndef MEDICALHELP_H
#define MEDICALHELP_H

#include <QDialog>
#include<key.h>
#include<QLineEdit>
#include<QtNetwork>

namespace Ui {
class MedicalHelp;
}

class MedicalHelp : public QDialog
{
    Q_OBJECT
    
public:
    explicit MedicalHelp(QWidget *parent = 0);
    ~MedicalHelp();
    void writeData();
    bool eventFilter(QObject *target, QEvent *event);

private slots:
    void on_backButton_clicked();
    void setText(QString);
    void readMessage();
    void spendMessage();
    void showRecipe(QString text);
    void showSelectedMedicineRedundant();
private:
    Ui::MedicalHelp *ui;
    QWidget *pre;
    Key *im;
    QLineEdit *as;
    QTcpSocket *client;
    QString receiptMsg;
    QString SendMsg;
private:
    void addItemToNameComBox();

};

#endif // MEDICALHELP_H
