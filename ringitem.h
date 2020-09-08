#ifndef RINGITEM_H
#define RINGITEM_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>

class RingItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit RingItem(int startAngle,int endAngle,QRectF rect,QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

signals:

public slots:

private:
    int m_startAngle;
    int m_endAngle;
    QRectF m_rect;

};

#endif // RINGITEM_H
