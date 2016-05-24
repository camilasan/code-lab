#include "game.h"
#include "man.h"
#include "bubble.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>

Game::Game(QGraphicsScene *scene, QGraphicsView *view)
{
    m_scene = scene;
    m_view = view;

    m_man = new Man(scene, view, this);
    Bubble *b = new Bubble(scene);

    m_text = new QGraphicsTextItem();
    m_scene->addItem(m_text);

    m_arrow = new QGraphicsTextItem();
    m_scene->addItem(m_arrow);

    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), SLOT(stopGame()));
    m_timer->start(50000);
    m_count = 50000;

    m_countdown = new QTimer();
    connect(m_countdown, SIGNAL(timeout()), SLOT(countTime()));
    m_countdown->start(10);

    m_text->setPos(2,2);
    m_text->setDefaultTextColor(Qt::red);

    m_arrow->setPos(200,2);
    m_arrow->setDefaultTextColor(Qt::blue);
    m_num_arrow = 10;
    m_arrow->setPlainText("Arrows: " + QString::number(m_num_arrow));

}

void Game::stopGame(){
    m_countdown->stop();
    m_text->setPlainText("GAME OVER ! :(");
    m_man->gameOver(qreal(0));
}

void Game::countTime(){
    m_text->setPlainText(QString::number(m_count));
    m_count-=10;

''}

void Game::countArrows(){
    if(m_num_arrow>0){
        m_num_arrow-=1;
    }else{
        stopGame();
    }
    m_arrow->setPlainText("Arrows: " + QString::number(m_num_arrow));
}
