#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>

class Butterfly : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QGraphicsItem *parent = nullptr);
    void timerEvent(QTimerEvent *);
    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;
};

#endif // BUTTERFLY_H
