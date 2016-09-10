#ifndef SON_H
#define SON_H

#include <QWidget>
#include <QLabel>
#include <info.h>
#include <sur.h>
#include <dor.h>
#include <sick.h>
#include <ces.h>
#include <tool.h>


namespace Ui {
class son;
}

class son : public QWidget
{
    Q_OBJECT
    
public:
    explicit son(QWidget *parent = 0);
    void setName(QString name);
    ~son();
    
private:
    Ui::son *ui;
    info *infor;
    sur *sut;
    dor *dot;
    sick *sic;
    ces *tes;
    tool *too;
    QString name;
private slots:
    void showinfo();
    void su();
    void dom();
    void sim();
    void tec();
    void tol();

};

#endif // SON_H
