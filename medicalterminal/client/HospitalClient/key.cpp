#include "key.h"
#include "ui_key.h"

Key::Key(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Key)
{
    setWindowFlags(Qt::Tool|Qt::FramelessWindowHint);
    ui->setupUi(this);
    QPixmap pixmap("://image/playerground.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    this->setPalette(palette);
}

Key::~Key()
{
    delete ui;
}


//void Key::on_shuru_cursorPositionChanged(int arg1, int arg2)
//{

//}



void Key::on_fanhui_clicked()
{
    this->close();
}



void Key::on_anjian1_clicked()
{
    ui->shuru->insert("1");
}

void Key::on_anjian2_clicked()
{
    ui->shuru->insert("2");
}

void Key::on_anjian3_clicked()
{
    ui->shuru->insert("3");
}

void Key::on_anjian4_clicked()
{
     ui->shuru->insert("4");
}

void Key::on_anjian5_clicked()
{
     ui->shuru->insert("5");
}

void Key::on_anjian6_clicked()
{
     ui->shuru->insert("6");
}

void Key::on_anjian7_clicked()
{
     ui->shuru->insert("7");
}

void Key::on_anjian8_clicked()
{
     ui->shuru->insert("8");
}

void Key::on_anjian9_clicked()
{
     ui->shuru->insert("9");
}

void Key::on_anjian0_clicked()
{
     ui->shuru->insert("0");
}

void Key::on_Q_clicked()
{
   ui->shuru->insert("q");
}

void Key::on_W_clicked()
{
     ui->shuru->insert("w");
}

void Key::on_E_clicked()
{
     ui->shuru->insert("e");
}

void Key::on_R_clicked()
{
     ui->shuru->insert("r");
}

void Key::on_T_clicked()
{
     ui->shuru->insert("t");
}

void Key::on_Y_clicked()
{
     ui->shuru->insert("y");
}


void Key::on_I_clicked()
{
     ui->shuru->insert("i");
}

void Key::on_O_clicked()
{
     ui->shuru->insert("o");
}

void Key::on_P_clicked()
{
     ui->shuru->insert("p");
}

void Key::on_A_clicked()
{
     ui->shuru->insert("a");
}

void Key::on_S_clicked()
{
     ui->shuru->insert("s");
}

void Key::on_D_clicked()
{
     ui->shuru->insert("d");
}

void Key::on_F_clicked()
{
     ui->shuru->insert("f");
}

void Key::on_G_clicked()
{
     ui->shuru->insert("g");
}

void Key::on_H_clicked()
{
     ui->shuru->insert("h");
}

void Key::on_J_clicked()
{
     ui->shuru->insert("j");
}

void Key::on_K_clicked()
{
     ui->shuru->insert("k");
}

void Key::on_L_clicked()
{
     ui->shuru->insert("l");
}

void Key::on_Z_clicked()
{
     ui->shuru->insert("z");
}

void Key::on_X_clicked()
{
     ui->shuru->insert("x");
}

void Key::on_C_clicked()
{
     ui->shuru->insert("c");
}

void Key::on_V_clicked()
{
     ui->shuru->insert("v");
}

void Key::on_B_clicked()
{
     ui->shuru->insert("b");
}

void Key::on_N_clicked()
{
     ui->shuru->insert("n");
}

void Key::on_M_clicked()
{
     ui->shuru->insert("m");
}
void Key::on_u_clicked()
{
    ui->shuru->insert("u");
}

void Key::on_ok_clicked()
{
    QString s=ui->shuru->text();
    emit setvalue(s);
    ui->shuru->clear();
    this->hide();
}

void Key::on_shanchu_clicked()
{
    QString s=ui->shuru->text();
    int ha=s.length();
    QString s2=s.remove(ha-1,1);
    ui->shuru->setText(s2);
}

void Key::on_clean_clicked()
{
    ui->shuru->setText("");
}
