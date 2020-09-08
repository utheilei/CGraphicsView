#include "arrowitem.h"
#include <QFontMetricsF>
#include <QMessageBox>
#include <QDebug>

ArrowItem::ArrowItem(QString text,QRectF rect,QGraphicsItem *parent) : QGraphicsItem(parent)
{
    m_text = text;
    m_rect = rect;
    this->setFlags(QGraphicsItem::ItemIsSelectable|QGraphicsItem::ItemIsMovable);
}

QRectF ArrowItem::boundingRect() const
{
    return m_rect;
}

void ArrowItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen;
    pen.setCapStyle(Qt::FlatCap);
    pen.setWidthF(2);
    painter->setBrush(m_bgcolor);
    QPointF points[6] = {
          m_rect.topLeft(),
          QPointF(m_rect.topRight().x()-20,m_rect.topRight().y()),
          QPointF(m_rect.topRight().x(),m_rect.topRight().y()+m_rect.height()/2.0),
          QPointF(m_rect.bottomRight().x()-20,m_rect.bottomRight().y()),
          m_rect.bottomLeft(),
          QPointF(m_rect.topLeft().x()+20,m_rect.topLeft().y()+m_rect.height()/2.0)
      };
    painter->drawPolygon(points,6);

    QFont font;     //设置字体
    font.setPointSize(10);
    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing,0);
    painter->setFont(font);
    QFontMetricsF fontMetrics(font);
    double textWidth = fontMetrics.width(m_text);   //获取字体长度/宽度
    double textHeight = fontMetrics.height();
    int pointX = m_rect.center().x() - textWidth/2.0;
    int pointY = m_rect.center().y() + textHeight/4.0;

    painter->drawText(pointX,pointY,m_text);
}

int ArrowItem::type() const
{
    return ARROWITEM_TYPE;
}

QColor ArrowItem::getBgcolor()
{
    return m_bgcolor;
}

QString ArrowItem::getContent()
{
    return m_text;
}

void ArrowItem::setBgcolor(QColor bgcolor)
{
    m_bgcolor = bgcolor;
}

void ArrowItem::setContent(QString content)
{
    m_text = content;
}
