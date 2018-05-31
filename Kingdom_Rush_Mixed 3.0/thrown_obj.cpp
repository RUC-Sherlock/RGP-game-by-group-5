#include "thrown_obj.h"
#include <cmath>
Thrown_obj::Thrown_obj(const QPoint & obj_location,const QPoint & rlocation,const QPoint & heart,const int img_num,const char **dir_set,
                       const int speed,const int stepmax):
    Abstract_obj(obj_location,rlocation,img_num,dir_set),_speed(speed),_stepmax(stepmax)
{
    int x1=heart.x()-obj_location.x();
    int y1=heart.y()-obj_location.y();
    double distance=sqrt(x1*x1+y1*y1);
    _dx=x1*_speed/distance;
    _dy=y1*_speed/distance;
}


void Thrown_obj::move()
{
    QPoint newlocation=getObj_location()+QPoint(_dx,_dy);
    setObj_location(newlocation);
    _stepmax--;
    if(_stepmax==0) deleteIt();
}


