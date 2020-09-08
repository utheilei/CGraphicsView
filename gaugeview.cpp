#include "gaugeview.h"
#include "ringitem.h"
#include <QDebug>
#include <QMessageBox>

GaugeView::GaugeView(QWidget *parent)
    : QGraphicsView(parent)
    , m_scene(new Scene(this))
{
    setMouseTracking(true);
    m_menu = new QMenu;
    QAction *addAction = new QAction(tr("添加"));
    QAction *removeAction = new QAction(tr("删除"));
    QAction *msgAction = new QAction(tr("详细信息"));
    m_menu->addAction(addAction);
    m_menu->addAction(removeAction);
    m_menu->addAction(msgAction);
    connect(msgAction,&QAction::triggered,[=](){
        QMessageBox::about(nullptr,tr("详细信息"),"UOS");
    });
}

Scene *GaugeView::getScene()
{
    return m_scene;
}

void GaugeView::resizeEvent(QResizeEvent *e)
{
    QGraphicsView::resizeEvent(e);

    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    m_scene->setSceneRect(this->rect());
    setScene(m_scene);
    setCacheMode(CacheBackground);

    fitInView(this->scene()->sceneRect(), Qt::IgnoreAspectRatio);    //这样就没法缩放了
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    //scale(1.5, 1.5);
    m_weight= e->size().width();
    m_height= e->size().height();
    qDebug()<<m_weight<<m_height<<m_scene->sceneRect();
}

void GaugeView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

void GaugeView::mousePressEvent(QMouseEvent *event)
{
    m_ItemList = items();
    QGraphicsItem *m_item = itemAt(event->pos());

    if(event->button()==Qt::LeftButton)
    {
        if(m_item != nullptr)
        {
            qDebug()<<m_item<<m_item->data(Qt::UserRole)<<m_item->type();
            QString str = m_item->data(Qt::UserRole).toString();
            if(m_item->data(Qt::UserRole).isValid())
            {
                emit signalItem(m_item);
            }
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void GaugeView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void GaugeView::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug()<<event->pos()<<event->globalPos();
    m_menu->exec(event->globalPos());
    QGraphicsView::contextMenuEvent(event);
}
