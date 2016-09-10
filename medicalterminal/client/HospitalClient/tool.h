#ifndef TOOL_H
#define TOOL_H

#include <QDialog>
#include <data.h>
#include<alarmclock.h>
#include<medicalhelp.h>
#include<th.h>
#include<calculator.h>
namespace Ui {
class tool;
}

class tool : public QDialog
{
    Q_OBJECT
    
public:
    explicit tool(QWidget *parent = 0);
    ~tool();
    
private:
    Ui::tool *ui;
    QWidget *pre;
    Data *data;
    AlarmClock *clock;
    MedicalHelp *helper;
    TH *th;
    calculator *cal;
private slots:
    void on_calculatorButton_clicked();
    void on_showTimeButton_clicked();
    void on_THButton_clicked();
    void on_medicalHelpButton_clicked();
    void on_clockButton_clicked();
    void on_backButton_clicked();
};

#endif // TOOL_H
