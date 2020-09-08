#ifndef GAUGEVIEW_H
#define GAUGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include "scene.h"
#include <QMenu>

class GaugeView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GaugeView(QWidget *parent = nullptr);
    Scene *getScene();

signals:
    void signalItem(QGraphicsItem*);

public slots:

protected:
    void resizeEvent(QResizeEvent *e) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    int m_weight;
    int m_height;
    Scene *m_scene;
    QList<QGraphicsItem*> m_ItemList;
    QMenu *m_menu;
};

#endif // GAUGEVIEW_H
