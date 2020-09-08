#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ringitem.h"
#include "arrowitem.h"
#include "buttonitem.h"
#include "butterfly.h"
#include "mouse.h"
#include <QTimer>

class Scene;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Scene *m_graphicsScene;
    RingItem *ringItem;
    ArrowItem *m_arrowItem;
    ButtonItem *m_buttonItem;
    ButtonItem *m_buttonItem1;
    QList<ArrowItem*> m_arrowItemList;
    int count=0;
    QTimer timer;
};

#endif // MAINWINDOW_H
