#include "scene.h"

Scene::Scene()
{
    //setSceneRect(-205, -245, 800, 600);
    setItemIndexMethod(QGraphicsScene::NoIndex); 
    
    m_snake = new Snake();    
    addItem(m_snake); 

    //add food
    m_food = new Food();        
    addItem(m_food);    
    
    view.setScene(this);
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setBackgroundBrush(Qt::white);
    view.setWindowTitle("Snake");
    view.show();    
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    m_snake->walk(event->key());
    QGraphicsScene::keyPressEvent(event);
    
}









