#ifndef BUTTONITEM_H
#define BUTTONITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#define BUTTONITEM_TYPE  100

class ButtonItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QColor bgcolor READ getBgcolor WRITE setBgcolor)

public:
    explicit ButtonItem(QString text,QRectF rect,QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    int	type() const override;

    QString getContent();
    QColor getBgcolor();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

signals:
    void signalclicked();

public slots:
    void setBgcolor(QColor bgcolor);

private:
    QString m_text;
    QRectF m_rect;
    QColor m_bgcolor = Qt::red;
};

#endif // BUTTONITEM_H
