#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <math.h>
#include <QtDebug>


namespace Ui {
class calculator;
}

class calculator : public QWidget
{
    Q_OBJECT
    
public:
    explicit calculator(QWidget *parent = 0);
    ~calculator();
   void setPre(QWidget *parent);
private slots:
    void on_bt_0_clicked();

    void on_bt_1_clicked();

    void on_bt_2_clicked();

    void on_bt_3_clicked();

    void on_bt_4_clicked();

    void on_bt_5_clicked();

    void on_bt_6_clicked();

    void on_bt_7_clicked();

    void on_bt_8_clicked();

    void on_bt_9_clicked();

    void on_bt_dot_clicked();

    void on_bt_equ_clicked();

    void on_bt_jia_clicked();

    void on_bt_jian_clicked();

    void on_bt_cheng_clicked();

    void on_bt_chu_clicked();

    void on_bt_ce_clicked();

    void on_bt_c_clicked();

    void on_pushButton_clicked();

private:

    Ui::calculator *ui;
    QString a1;      //操作数1
    QString a2;      //操作数2
    bool clicked;        //设置按钮是否锁死
    bool dot;
    char operate;
    QWidget *pre;
};

#endif // CALCULATOR_H
