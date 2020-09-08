#include "butterfly.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QtMath>

Butterfly::Butterfly(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    pix_up.load(":/aaa.jpg");
    pix_up = pix_up.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    //pix_down.load(":/images/butterfly2.PNG");
    //up = true;
    startTimer(100);
}

void Butterfly::timerEvent(QTimerEvent *)
{
    qreal edgex = scene()->sceneRect().right()+boundingRect().width()/2;
    qreal edgetop = scene()->sceneRect().top()+boundingRect().height()/2;
    qreal edgebottom = scene()->sceneRect().bottom()+boundingRect().height()/2;

    if (pos().x() >= edgex)
        setPos(scene()->sceneRect().left(),pos().y());
    if (pos().y() <= edgetop)
        setPos(pos().x(),scene()->sceneRect().bottom());
    if (pos().y() >= edgebottom)
        setPos(pos().x(),scene()->sceneRect().top());

    angle += (qrand()%10)/20.0;
    qreal dx = qFabs(qSin(angle*M_PI)*10.0);
    qreal dy = (qrand()%20)-10.0;

    setPos(mapToParent(dx,dy));
    update();
}

QRectF Butterfly::boundingRect() const
{
    qreal adjust = 8;
    return QRectF(-pix_up.width()/2-adjust,-pix_up.height()/2-adjust,
                  pix_up.width()+adjust*2,pix_up.height()+2*adjust);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(),pix_up);
}
