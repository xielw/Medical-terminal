#ifndef KEY_H
#define KEY_H

#include <QDialog>

namespace Ui {
class Key;
}

class Key : public QDialog
{
    Q_OBJECT
signals:
    void setvalue(QString);
public:
    explicit Key(QWidget *parent = 0);
    ~Key();
    
private slots:
    void on_anjian1_clicked();

    void on_anjian2_clicked();

    void on_anjian3_clicked();

    void on_anjian4_clicked();

    void on_anjian5_clicked();

    void on_anjian6_clicked();

    void on_anjian7_clicked();

    void on_anjian8_clicked();

    void on_anjian9_clicked();

    void on_anjian0_clicked();

    void on_Q_clicked();

    void on_W_clicked();

    void on_E_clicked();

    void on_R_clicked();

    void on_T_clicked();

    void on_Y_clicked();

    void on_I_clicked();

    void on_O_clicked();

    void on_P_clicked();

    void on_A_clicked();

    void on_S_clicked();

    void on_D_clicked();

    void on_F_clicked();

    void on_G_clicked();

    void on_H_clicked();

    void on_J_clicked();

    void on_K_clicked();

    void on_L_clicked();

    void on_Z_clicked();

    void on_X_clicked();

    void on_C_clicked();

    void on_V_clicked();

    void on_B_clicked();

    void on_N_clicked();

    void on_M_clicked();
        void on_u_clicked();

    //void on_shuru_cursorPositionChanged(int arg1, int arg2);

    //void on_pushButton_clicked();

    void on_fanhui_clicked();

    void on_ok_clicked();

    void on_shanchu_clicked();

    void on_clean_clicked();


private:
    Ui::Key *ui;
};

#endif // KEY_H
