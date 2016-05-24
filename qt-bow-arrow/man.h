#ifndef MAN_H
#define MAN_H

#include "arrow.h"
#include <QObject>
#include <QGraphicsRectItem>

class QMouseEvent;
class QGraphicsScene;
class QGraphicsView;
class Game;

class Man : public QObject, public QGraphicsRectItem {
  
  Q_OBJECT
  public:
    Man(QGraphicsScene *scene, QGraphicsView *view, Game *g);
    bool eventFilter(QObject *object, QEvent *event);
    void getArrows();
    void gameOver(qreal n);

  public slots:
    void shoot();

  private:
    void walk(int k);
    QGraphicsScene *m_scene;
    QGraphicsView *m_view;
    Game *m_game;
    QMouseEvent *m_mouse;

};

#endif
 
