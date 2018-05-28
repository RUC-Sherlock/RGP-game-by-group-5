#ifndef ICEBALL_H
#define ICEBALL_H


#include "thrown_obj.h"

class Iceball : public Thrown_obj
{ 
public:
    Iceball(const QPoint & obj_location,const QPoint & heart);
    void draw(QPainter &p);
};

#endif // ICEBALL_H
