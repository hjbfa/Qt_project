#include "widget.h"
#include "ui_widget.h"
#include <QByteArray>
#include <QDebug>

#define BVT_STX (0x80)        /* 帧起始字符 */
#define BVT_ETX (0x81)        /* 帧结束字符 */

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QByteArray byteArray("hello world");
    qDebug()<<"byteArray = "<<byteArray<<" "<<byteArray.length();;
    char ch = 0x21;
    byteArray.append(ch);
    qDebug()<<"byteArray = "<<byteArray<<" "<<byteArray.length();
    ch = 0x24;
    byteArray.insert(0, ch);
    qDebug()<<"byteArray = "<<byteArray<<" "<<byteArray.length();

    ch = 0x80;
    byteArray.insert(0, ch);
    qDebug()<<"byteArray = "<<byteArray<<" "<<byteArray.length();
    if ((unsigned char)byteArray.at(0) == BVT_STX)
    {
        qDebug()<<"byteArray.at(0) = 0x80";
    }
    else
    {
        qDebug()<<"byteArray.at(0) != 0x80";
    }
    getByteArrayReference(byteArray);
    getByteArrayReference2(byteArray);
}

Widget::~Widget()
{
    delete ui;
}

QByteArray& Widget::getByteArrayReference(QByteArray &pArray)
{
    pArray.append("lb2616 is coming!");
    qDebug()<<__PRETTY_FUNCTION__<<"pArray.length = "<<pArray.length()<<pArray;
    return pArray;
}

QByteArray& Widget::getByteArrayReference2(QByteArray &pArray)
{
    QByteArray tmp;
    tmp = pArray;
    tmp.append("lb2616 is coming!");
    qDebug()<<__PRETTY_FUNCTION__<<"pArray.length = "<<tmp.length()<<tmp;
}
