#ifndef CES_H
#define CES_H

#include <QDialog>
#include<bloodpressure.h>
#include<pulse.h>
#include<bloodglucose.h>
namespace Ui {
class ces;
}

class ces : public QDialog
{
    Q_OBJECT
    
public:
    explicit ces(QWidget *parent = 0);
    ~ces();
    
private:
    Ui::ces *ui;
    QWidget *pre;
    BloodPressure *bp;
    BloodGlucose *glucose;
    Pulse *pulse;
private slots:
    void close5();
    void on_bloodPressureButton_clicked();
    void on_bloodGlucoseButton_clicked();
    void on_pulseButton_clicked();
};

#endif // CES_H
