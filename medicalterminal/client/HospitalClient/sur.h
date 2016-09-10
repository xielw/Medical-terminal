#ifndef SUR_H
#define SUR_H
#include "floormap.h"
#include <QDialog>
#include<test.h>
namespace Ui {
class sur;
}

class sur : public QDialog
{
    Q_OBJECT
    
public:
    explicit sur(QWidget *parent = 0);

    ~sur();
private:
    Ui::sur *ui;
    QWidget*pre;
    FloorMap *floorMap;
private slots:
    void bac();
    void on_searchButton_clicked();
};

#endif // SUR_H
