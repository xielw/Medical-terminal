#ifndef TH_H
#define TH_H

#include <QDialog>

namespace Ui {
class TH;
}

class TH : public QDialog
{
    Q_OBJECT
    
public:
    explicit TH(QWidget *parent = 0);
    ~TH();
    
private slots:
    void on_backButton_clicked();

private:
    Ui::TH *ui;
    QWidget *pre;
};

#endif // TH_H
