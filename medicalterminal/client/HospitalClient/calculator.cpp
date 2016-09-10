#include "calculator.h"
#include "ui_calculator.h"
#include <QPixmap>
#include<QIcon>
calculator::calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calculator)
{

    ui->setupUi(this);
    setWindowIcon(QIcon("://image/close_hover.png"));


    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap pix(tr("://image/cancel_red.png"));
    pix.scaled(21,21);
    QIcon icon(pix);

    ui->pushButton->setIcon(icon);
    ui->pushButton->setFlat(true);
    ui->lineEdit->setText("0");

    a1="0";
    a2="0";
    operate='0';
    clicked=true;
    dot=true;

}


calculator::~calculator()
{
    delete ui;
}

void calculator::setPre(QWidget *parent)
{
    pre = parent;

}

void calculator::on_bt_0_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="0";
        }
        else{
            a2.append("0");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_1_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="1";
        }
        else{
            a2.append("1");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_2_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="2";
        }
        else{
            a2.append("2");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_3_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="3";
        }
        else{
            a2.append("3");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_4_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="4";
        }
        else{
            a2.append("4");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_5_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="5";
        }
        else{
            a2.append("5");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_6_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="6";
        }
        else{
            a2.append("6");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_7_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="7";
        }
        else{
            a2.append("7");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_8_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="8";
        }
        else{
            a2.append("8");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_9_clicked()
{
    if(clicked){
        if(a2=="0"){
            a2="9";
        }
        else{
            a2.append("9");
        }
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_dot_clicked()
{
    if(clicked){
        if(dot){
            if(a2=="0"){
                a2="0.";
            }
            else{
                a2.append(".");
            }
            dot=false;
            ui->lineEdit->setText(a2);
        }
    }
}

void calculator::on_bt_equ_clicked()
{
    if(clicked){
        float num1,num2;
        if(operate=='0'){
            a1=a2;
            a2="0";
            ui->lineEdit->setText(a1);
            operate='=';
            dot=true;
        }
        else{
            num1=a1.toFloat();
            num2=a2.toFloat();
            switch (operate) {
            case '+':
                num1=num1+num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '-':
                num1=num1-num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '*':
                num1=num1*num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '/':
                if(num2==0){
                    ui->lineEdit->setText("除数不能为0");
                    clicked=false;
                }
                else{
                    num1=num1/num2;
                    a1=QString("%1").arg(num1);
                    ui->lineEdit->setText(a1);
                }
                break;
            default:
                ui->lineEdit->setText(a1);
                break;
            }
            a2="0";
            operate='=';
            dot=true;
        }
    }
}

void calculator::on_bt_jia_clicked()
{
    if(clicked){
        float num1,num2;
        if(operate=='0'){
            a1=a2;
            a2="0";
            operate='+';
            dot=true;
        }
        else{
            num1=a1.toFloat();
            num2=a2.toFloat();
            switch (operate) {
            case '+':
                num1=num1+num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '-':
                num1=num1-num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '*':
                num1=num1*num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '/':
                if(num2==0){
                    ui->lineEdit->setText("除数不能为0");
                    clicked=false;
                }
                else{
                    num1=num1/num2;
                    a1=QString("%1").arg(num1);
                    ui->lineEdit->setText(a1);
                }
                break;
            default:
                ui->lineEdit->setText(a1);
                break;
            }
            a2="0";
            operate='+';
            dot=true;
        }
    }
}

void calculator::on_bt_jian_clicked()
{
    if(clicked){
        float num1,num2;
        if(operate=='0'){
            a1=a2;
            a2="0";
            operate='-';
            dot=true;
        }
        else{
            num1=a1.toFloat();
            num2=a2.toFloat();
            switch (operate) {
            case '+':
                num1=num1+num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '-':
                num1=num1-num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '*':
                num1=num1*num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '/':
                if(num2==0){
                    ui->lineEdit->setText("除数不能为0");
                    clicked=false;
                }
                else{
                    num1=num1/num2;
                    a1=QString("%1").arg(num1);
                    ui->lineEdit->setText(a1);
                }
                break;
            default:
                ui->lineEdit->setText(a1);
                break;
            }
            a2="0";
            operate='-';
            dot=true;
        }
    }
}

void calculator::on_bt_cheng_clicked()
{
    if(clicked){
        float num1,num2;
        if(operate=='0'){
            a1=a2;
            a2="0";
            operate='*';
            dot=true;
        }
        else{
            num1=a1.toFloat();
            num2=a2.toFloat();
            switch (operate) {
            case '+':
                num1=num1+num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '-':
                num1=num1-num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '*':
                num1=num1*num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '/':
                if(num2==0){
                    ui->lineEdit->setText("除数不能为0");
                    clicked=false;
                }
                else{
                    num1=num1/num2;
                    a1=QString("%1").arg(num1);
                    ui->lineEdit->setText(a1);
                }
                break;
            default:
                ui->lineEdit->setText(a1);
                break;
            }
            a2="0";
            operate='*';
            dot=true;
        }
    }
}

void calculator::on_bt_chu_clicked()
{
    if(clicked){
        float num1,num2;
        if(operate=='0'){
            a1=a2;
            a2="0";
            operate='/';
            dot=true;
        }
        else{
            num1=a1.toFloat();
            num2=a2.toFloat();
            switch (operate) {
            case '+':
                num1=num1+num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '-':
                num1=num1-num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '*':
                num1=num1*num2;
                a1=QString("%1").arg(num1);
                ui->lineEdit->setText(a1);
                break;
            case '/':
                if(num2==0){
                    ui->lineEdit->setText("除数不能为0");
                    clicked=false;
                }
                else{
                    num1=num1/num2;
                    a1=QString("%1").arg(num1);
                    ui->lineEdit->setText(a1);
                }
                break;
            default:
                ui->lineEdit->setText(a1);
                break;
            }
            a2="0";
            operate='/';
            dot=true;
        }
    }
}

void calculator::on_bt_ce_clicked()
{
    if(clicked){
        a2="0";
        dot=true;
        ui->lineEdit->setText(a2);
    }
}

void calculator::on_bt_c_clicked()
{
    a1="0";
    a2="0";
    operate='0';
    clicked=true;
    dot=true;
    ui->lineEdit->setText(a2);
}

void calculator::on_pushButton_clicked()
{
     close();
    pre->show();

}
