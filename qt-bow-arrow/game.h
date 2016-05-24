#ifndef GAME_H
#define GAME_H


#include <QObject>
#include <QTimer>

class Man;
class QGraphicsScene;
class  QGraphicsView;
class QGraphicsTextItem;

class Game : public QObject {

    Q_OBJECT
    public:
        Game(QGraphicsScene *scene,  QGraphicsView *view);
        void countArrows();

    public slots:
        void stopGame();
        void countTime();

    private:
        QTimer *m_timer;
        QTimer *m_countdown;
        QGraphicsScene *m_scene;
        QGraphicsView *m_view;
        QGraphicsTextItem *m_text;
        QGraphicsTextItem *m_arrow;
        Man *m_man;
        int m_count;
        int m_num_arrow;


};

#endif // GAME_H
