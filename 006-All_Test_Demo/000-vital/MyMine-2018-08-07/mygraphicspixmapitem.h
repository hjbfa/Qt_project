#ifndef MYGRAPHICSPIXMAPITEM_H
#define MYGRAPHICSPIXMAPITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

/*
 * class MyGraphicsPixmapItem : public QGraphicsPixmapItem
 * we must Inherits:QObject, otherwise will encounter error as follows
 * Compile error: ‘staticMetaObject’ is not a member of ‘QGraphicsPixmapItem
*/
class MyGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit MyGraphicsPixmapItem();
    void showMine();

    int getIsMineflag() const;
    void setIsMineflag(int isMineflag);

    int getButtonStatus() const;
    void setButtonStatus(int buttonStatus);

    int getMineSNumber() const;
    void setMineSNumber(int mineSNumber);
    ~MyGraphicsPixmapItem();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event ); //鼠标点击事件

private:
    void setImage(QString pPicName); //设置图片
    enum
    {
        NONE_PRESSED = 0,   // 0未按
        RIGHT_PRESSED,      // 1按下右键
        LEFT_PRESSED        // 2 按下左键
    };

private:
    int mIsMineflag;        // 标识是否为雷
    int mButtonStatus;      // 标识按钮状态 0未按  1按下右键  2 按下左键
    int mMineSNumber;       // 标识周围雷数

};

#endif // MYGRAPHICSPIXMAPITEM_H
