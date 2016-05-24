#include "man.h"
#include "game.h"
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

Man::Man(QGraphicsScene *scene, QGraphicsView *view, Game *g){
    m_scene = scene;
    m_view = view;
    m_game = g;
    setRect(5, 30, 20, 20);
    setBrush(Qt::black);
    m_view->installEventFilter(this);
    m_scene->addItem(this);
    setAcceptDrops(true);
}

void Man::walk(int k){
    switch(k){
      case Qt::Key_Down:
           setPos(pos() + QPointF(0, 10));
           break;
      case Qt::Key_Up:
           setPos(pos() + QPointF(0, -10));
           break;
    }
}

void Man::shoot(){
   new Arrow(m_scene, m_view, this);
   m_game->countArrows();
}

void Man::gameOver(qreal n){
    setBrush(Qt::BrushStyle());
    m_view->removeEventFilter(this);
}


bool Man::eventFilter(QObject *obj, QEvent *event){

    if (event->type() == QEvent::KeyPress){
        QKeyEvent *k = static_cast<QKeyEvent*>(event);
        walk(k->key());
    }else if(event->type() == QEvent::MouseButtonPress){
        shoot();
    }else{
        return false;
    }

    return true;
}


