#include "man.h"
#include "arrow.h"
#include "bubble.h"
#include "game.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>


int main(int argc, char *argv[]){
  QApplication app(argc, argv);
  QGraphicsView *view = new QGraphicsView();
  QGraphicsScene *scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600);
  Game *g = new Game(scene, view);
  view->setScene(scene);
  view->setDragMode(QGraphicsView::NoDrag);
  view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Bow Arrow"));
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setRenderHint(QPainter::Antialiasing, true);
  view->setCacheMode(QGraphicsView::CacheBackground);
  view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  view->setDragMode(QGraphicsView::ScrollHandDrag);
  view->setMaximumSize(800, 600);
  view->resize(800, 600);
  view->setBackgroundBrush(Qt::white);
  view->show();
  return app.exec();
}
 
