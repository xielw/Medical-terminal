#include "mainwindow.h"
#include <QApplication>
#include<QTextCodec>
#include "connection.h"
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
  if (!createConnection()) return 1;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
