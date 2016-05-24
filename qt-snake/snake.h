#ifndef SNAKE_H
#define SNAKE_H

#include "food.h"
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

template<class T >
class QList;

class Snake : public QObject, public QGraphicsItem
{

    Q_OBJECT
    public:
	Snake();
	void walk(int k);	
	void eating();
	QList <QGraphicsRectItem*> quadradinhos;
	QGraphicsRectItem new_quadradinho;
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	
    private slots:
	void walk();
	
    private:
	int i;
	QTimer *timer;
	QPainter m_painter;	
	
	
};

#endif 