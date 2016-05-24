#include "food.h"

#include <math.h>

static int n_random = qrand() % 256;

Food::Food()
{

    i = 2;
    setRect(-150, -150, 10, 10); 
    setBrush(Qt::blue);
    
    timer_blink = new QTimer();
    timer_blink->setSingleShot(true);
    connect(timer_blink, SIGNAL(timeout()), SLOT(blink()));
    timer_blink->start(1000);
    
    timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), SLOT(hidding()));
    timer->start(6000); 
    
}

void Food::hidding()
{
  hide();
  setPos(::sin((i * 6.28) / n_random-1 ) * 200, ::cos((i * 6.28) / n_random-1 ) * 200);
  show();  
  i+=2;
  timer->start(6000);
}

void Food::blink()
{
  if(isVisible()){ 
    hide();    
  }else{
    show();
  }
  timer_blink->start(350);
}





