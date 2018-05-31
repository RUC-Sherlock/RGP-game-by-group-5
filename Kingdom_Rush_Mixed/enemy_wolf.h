#ifndef ENEMY_WOLF_H
#define ENEMY_WOLF_H
#include "constant.h"
#include "live_player.h"
#include <QPoint>

class Enemy_wolf:public Live_player

{
    Q_OBJECT
public:
    Enemy_wolf(int route);
    void lrun();
    void rrun();
    void dying();
    void draw(QPainter &p);
    bool hurtedBy(Thrown_obj &obj);
    void process(const Live_player & obj){}
    ~Enemy_wolf(){}

//private:
    enum Condition{lrun1,lrun2,lrun3,lrun4,lrun5,lrun6,lrun7,lrun8,
                   rrun1,rrun2,rrun3,rrun4,rrun5,rrun6,rrun7,rrun8,
                   lstand,rstand,
                  dying1,dying2,dying3,dying4,dying5,dying6,dying7,dying8,
                  dying9,dying10,dying11,dying12,dying13,dying14,dying15,dying16};
    Condition _condition;
    int point_destination;//标记下一个要去的点是第几个。针对destination数组中的列数，0-3
    int _route;
};

#endif // ENEMY_WOLF_H
