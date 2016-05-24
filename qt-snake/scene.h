#ifndef SCENE_H
#define SCENE_H

#include "snake.h"
#include "food.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDebug>


class Scene : public QGraphicsScene
{

    public:
	Scene();
	void keyPressEvent(QKeyEvent *event);

    private:	
	QGraphicsView view;
	QPainter painter;
	Snake *m_snake;	
	Food *m_food;
	
};

#endif 