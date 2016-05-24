#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsPathItem>

class QGraphicsScene;
class QGraphicsView;
class Man;

class Arrow : public QObject, public QGraphicsPathItem{
  
  Q_OBJECT
  public:
    Arrow(QGraphicsScene *scene, QGraphicsView *view, Man *m);
    QPainterPath m_path;
    QList<QGraphicsPathItem*> m_arrows;

  public slots:
    void go();
    
  private:
    QGraphicsPathItem *m_triangle;
    QTimer *m_timer;
    QGraphicsScene *m_scene;
    Man *m_man;

    
};

#endif
 
