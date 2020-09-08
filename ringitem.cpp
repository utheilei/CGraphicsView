#include "ringitem.h"

RingItem::RingItem(int startAngle,int endAngle,QRectF rect,QGraphicsItem *parent) : QGraphicsItem(parent)
{
    m_startAngle = startAngle;
    m_endAngle = endAngle;
    m_rect = rect;
    this->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
}

QRectF RingItem::boundingRect() const
{
    return m_rect;
}

void RingItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    pen.setWidthF(20);
    int totalAngle = m_endAngle - m_startAngle;
    //绘制第一圆环
    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawArc(m_rect, (m_startAngle+totalAngle*3/4) * 16, totalAngle/4 * 16);

    //绘制第二圆环
    pen.setColor(Qt::blue);
    painter->setPen(pen);
    painter->drawArc(m_rect, (m_startAngle+totalAngle/4) * 16, totalAngle/2 * 16);

    //绘制第三圆环
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawArc(m_rect, m_startAngle * 16, totalAngle/4 * 16);
}
