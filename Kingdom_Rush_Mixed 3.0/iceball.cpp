#include "iceball.h"

static const char *dirset[]=
    {":/others/image/others/iceball.png"
    };
static const QPoint rlocation=QPoint(7,7);
static const int img_num=1;
static const int speed=30;
static const int stepmax=10;

Iceball::Iceball(const QPoint & obj_location, const QPoint &heart):
    Thrown_obj(obj_location,rlocation,heart,img_num,dirset,speed,stepmax){}


void Iceball::draw(QPainter &p)
{
    drawImage(p,0);
    move();
}
