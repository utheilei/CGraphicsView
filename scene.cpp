#include "scene.h"
#include <QDebug>
#include <QGraphicsView>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    //qDebug()<<event->scenePos();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
//    m_itemList = items();
//    QTransform transform;
//    QGraphicsItem *m_item = itemAt(event->scenePos(),transform);

//    if(event->button()==Qt::LeftButton)
//    {
//        qDebug()<<items()<<m_item<<event->pos();
//        if(m_item != nullptr)
//        {
//            qDebug()<<m_item;
//        }
    //    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}
