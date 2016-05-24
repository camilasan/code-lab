#ifndef BUBBLE_H
#define BUBBLE_H

#include <QList>
#include <QTimer>
#include <QObject>
#include <QGraphicsEllipseItem>



class QGraphicsScene;

class Bubble : public QObject {
  
  Q_OBJECT;
  public:
    Bubble(QGraphicsScene *scene);    
    QList<QGraphicsEllipseItem*> m_bubbles;
    
  private slots:
    void floating();
    
  private:    
    QGraphicsScene *m_scene;
    QTimer *m_timer;
  
};

#endif
 
 
