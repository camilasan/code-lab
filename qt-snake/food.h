#ifndef FOOD_H
#define FOOD_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>


class Food : public QObject, public QGraphicsRectItem
{

    Q_OBJECT
    public:
	Food();	
	
    public slots:
	void hidding();
	
    private slots:
	void blink();
		
    private:
        QTimer *timer;
	QTimer *timer_blink;
	int i;
	
};

#endif 