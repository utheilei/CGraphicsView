#include "mainwindow.h"
#include "gaugeview.h"
#include <QBoxLayout>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    this->setGeometry(500,300,600,400);
    QWidget *centerWidget = new QWidget;
    this->setCentralWidget(centerWidget);
    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    centerWidget->setLayout(vBoxLayout);
    GaugeView *gauge = new GaugeView;
    m_graphicsScene = gauge->getScene();
    QRect ringRect(0,0,100,100);

    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(ringRect);
    item->setPos(50,50);
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine *timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);

    for (int i=0; i<400; i++)
    {
        anim->setPosAt(i/400.0, QPointF(i,80));
    }
    timeLine->start();
    m_graphicsScene->addItem(item);

//    ringItem = new RingItem(-40,220,ringRect);
//    ringItem->setPos(100,100);
//    m_graphicsScene->addItem(ringItem);

    Butterfly *butterItem = new Butterfly;
    butterItem->setPos(200,100);
    m_graphicsScene->addItem(butterItem);

    QRect arrowRect(0,0,100,50);
    for (int i=0;i<6;i++) {
        m_arrowItem = new ArrowItem(tr("阶段%1").arg(i+1),arrowRect);
        m_arrowItem->setData(Qt::UserRole,tr("Arrow/%1").arg(i));
        m_arrowItem->setPos(50+i*80,200);
        m_arrowItemList.append(m_arrowItem);
        m_graphicsScene->addItem(m_arrowItem);
    }

    QRect buttonRect(0,0,80,40);
    m_buttonItem = new ButtonItem(tr("pervious"),buttonRect);
    m_buttonItem->setPos(150,300);
    m_buttonItem1 = new ButtonItem(tr("next"),buttonRect);
    m_buttonItem1->setPos(300,300);
    m_graphicsScene->addItem(m_buttonItem);
    m_graphicsScene->addItem(m_buttonItem1);

    for (int i = 0; i < 7; ++i) {
        Mouse *mouse = new Mouse;
        mouse->setPos(50+i*50,200);
        m_graphicsScene->addItem(mouse);
    }

    connect(&timer, SIGNAL(timeout()), m_graphicsScene, SLOT(advance()));
    timer.start(1000/33);

    connect(m_buttonItem1,&ButtonItem::signalclicked,[=](){
        if(count>=6)
            return;
        m_arrowItemList[count]->setBgcolor(Qt::green);
        m_arrowItemList[count]->update();
        count++;
    });
    connect(m_buttonItem,&ButtonItem::signalclicked,[=](){
        if(count>0)
        {
            --count;
            m_arrowItemList[count]->setBgcolor(Qt::white);
            m_arrowItemList[count]->update();
        }
    });
    connect(gauge,&GaugeView::signalItem,[=](QGraphicsItem *item){
        QStringList strList = item->data(Qt::UserRole).toString().split("/");
        count = strList[1].toInt()+1;
        if(item->type()==ARROWITEM_TYPE)
        {
            if(count>0)
            {
                for (int i=0;i<count;i++) {
                    m_arrowItemList[i]->setBgcolor(Qt::green);
                    m_arrowItemList[i]->update();
                }
            }
            else {
                ArrowItem *arrow = dynamic_cast<ArrowItem *>(item);
                arrow->setBgcolor(Qt::green);
                arrow->update();
            }
        }
    });
    //gauge->setRenderHint(QPainter::Antialiasing);//指定Render标签，抗锯齿
    //gauge->setCacheMode(QGraphicsView::CacheBackground);//缓存模式
    //gauge->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//场景重绘更新方式
    //gauge->setDragMode(QGraphicsView::ScrollHandDrag);//拖动模式，鼠标可拖动
    vBoxLayout->addWidget(gauge);
}

MainWindow::~MainWindow()
{

}
