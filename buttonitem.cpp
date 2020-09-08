#include "buttonitem.h"
#include <QDebug>
#include <QCursor>

ButtonItem::ButtonItem(QString text, QRectF rect, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    m_rect = rect;
    m_text = text;
    setAcceptHoverEvents(true);
}

QRectF ButtonItem::boundingRect() const
{
    return m_rect;
}

void ButtonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    pen.setWidthF(2);
    painter->setBrush(m_bgcolor);
    painter->drawRect(m_rect);

    QFont font;     //设置字体
    font.setPointSize(10);
    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing, 0);
    painter->setFont(font);
    QFontMetricsF fontMetrics(font);
    double textWidth = fontMetrics.width(m_text);   //获取字体长度/宽度
    double textHeight = fontMetrics.height();
    int pointX = m_rect.center().x() - textWidth / 2.0;
    int pointY = m_rect.center().y() + textHeight / 4.0;
    painter->drawText(pointX, pointY, m_text);
}

int ButtonItem::type() const
{
    return BUTTONITEM_TYPE;
}

QString ButtonItem::getContent()
{
    return m_text;
}

QColor ButtonItem::getBgcolor()
{
    return m_bgcolor;
}

void ButtonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        setCursor(Qt::ClosedHandCursor);
        emit signalclicked();
    }
    QGraphicsItem::mousePressEvent(event);
}

void ButtonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    QGraphicsItem::mouseReleaseEvent(event);
}

void ButtonItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    QGraphicsItem::hoverEnterEvent(event);
}

void ButtonItem::setBgcolor(QColor bgcolor)
{
    m_bgcolor = bgcolor;
}
