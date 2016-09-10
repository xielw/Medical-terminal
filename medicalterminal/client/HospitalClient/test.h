#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include<QMouseEvent>
namespace Ui {
class test;
}

class test : public QWidget
{
    Q_OBJECT
    
public:
    explicit test(QString floor,QString room,QWidget *parent = 0);
    ~test();
    void setPre(QWidget *parent);
void mouseDoubleClickEvent(QMouseEvent *);
private:
    Ui::test *ui;
    QPalette palette;
    QWidget *pre;

};

#endif // TEST_H
