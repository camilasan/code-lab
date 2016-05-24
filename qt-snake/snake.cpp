#include "snake.h"

#include <QSound>
#include <math.h>
#include <QtGui/qgraphicsitem.h>

static int n_snakes = qrand() % 256;

Snake::Snake()
{
    i = 1;       
    setPos(-200, -200);
    
    eating(); 
    qDebug() << "Rect:" <<  boundingRect();
    qDebug() << "size:" << quadradinhos.size();
  
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(walk()));
    timer->start(3000);    
    
}

void Snake::walk()
{
  setPos(::sin((i * 6.28) / n_snakes-1 ) * 200, ::cos((i * 6.28) / n_snakes-1 ) * 200);   
  i++;
  timer->start(3000);
}

void Snake::walk(int k)
{
  
    switch(k){
      case Qt::Key_Left:
	   //if(m_snake->pos().x() > qreal(0))
	    setPos(pos() + QPointF(-10, 0));
	   break;
      case Qt::Key_Right:
	   //if(m_snake->pos().x() < qreal(580))
	    setPos(pos() + QPointF(10, 0));
	   break;
      case Qt::Key_Down:
	   //if(m_snake->pos().y() < qreal(500))
	    setPos(pos() + QPointF(0, 10));
	   break;
      case Qt::Key_Up:
	   //if(m_snake->pos().y() > qreal(0))
	    setPos(pos() + QPointF(0, -10));
	   break;
    }
    
    qDebug() << "andando:" << boundingRect();;
   

}

void Snake::eating()
{   
 
  for(int i=1;i<4;i++){
    
    new_quadradinho.setParentItem(this);
    quadradinhos.insert(quadradinhos.size()+1, &new_quadradinho);
    QRectF s = boundingRect();
    new_quadradinho.setBrush(Qt::yellow);
    new_quadradinho.setRect(s.x()-s.width(), s.y(), 10, 10);
    
  }
  
}

QRectF Snake::boundingRect() const
{     

    return QRectF(pos().x(), pos().y(), 10*quadradinhos.size(), 10);
    
}
 

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *s, QWidget *w)
{
     painter->setBrush(Qt::yellow);
     painter->setPen(Qt::black);

}






