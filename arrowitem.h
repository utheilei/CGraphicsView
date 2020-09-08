#ifndef ARROWITEM_H
#define ARROWITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#define ARROWITEM_TYPE 88

class ArrowItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QColor bgcolor READ getBgcolor WRITE setBgcolor)
    Q_PROPERTY(QString content READ getContent WRITE setContent)

public:
    explicit ArrowItem(QString text,QRectF rect,QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    int	type() const override;

    QColor getBgcolor();
    QString getContent();

protected:
    //void contextMenuEvent(QGraphicsSceneContextMenuEvent *e) override;

signals:

public slots:
    void setBgcolor(QColor bgcolor);
    void setContent(QString content);

private:
    QString m_text;
    QRectF m_rect;
    QColor m_bgcolor = Qt::white;
};

#endif // ARROWITEM_H
