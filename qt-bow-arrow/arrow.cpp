#include "arrow.h"
#include "game.h"
#include "man.h"
#include "bubble.h"
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsScene>

static const int triangle[3][2] = {{ -6, -47 }, { +6, -47 }, { 0, -55 }};

Arrow::Arrow(QGraphicsScene *scene, QGraphicsView *view, Man *m){
  m_man = m;
  m_scene = scene;
  m_path.addPolygon(QPolygon(3, &triangle[0][0]));
  setPath(m_path);
  setBrush(Qt::green);
  setPos(m_man->pos().x()-25, m_man->pos().y()+40);
  setRotation(90);  
  m_scene->addItem(this);
  m_timer = new QTimer();
  connect(m_timer, SIGNAL(timeout()), SLOT(go()));
  m_timer->start(80);
  go();
}

void Arrow::go(){
    setX(pos().x()+10);

    if(collidingItems().size() > 1){
        for(int i = 0; i < collidingItems().size();i++){
            collidingItems().at(i)->setOpacity(0);
        }
    }

}



