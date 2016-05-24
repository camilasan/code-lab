#include "scene.h"
#include "snake.h"

#include <QtGui>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);    
    new Scene();
    return app.exec();
}
