#include "bubble.h"
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

Bubble::Bubble(QGraphicsScene *scene){
  m_scene = scene;  
  for(int i=1; i<11; i++){
    QGraphicsEllipseItem *e = new QGraphicsEllipseItem();    
    m_bubbles.prepend(e);
    if(m_bubbles.size()>1){
      e->setRect(400+(23*(i-1)), 540, 22, 32);
    }else{
      e->setRect(400, 540, 22, 32);
    }
    e->setBrush(Qt::red);
    m_scene->addItem(e); 
  }  
  
  m_timer = new QTimer();    
  connect(m_timer, SIGNAL(timeout()), SLOT(floating()));
  m_timer->start(1500);

}

void Bubble::floating(){
  for(int i=0; i<10; i++){
    QGraphicsEllipseItem *e = m_bubbles.value(i);
    e->setPos(e->pos().x(), e->pos().y()-50);
  }

}




 
 
