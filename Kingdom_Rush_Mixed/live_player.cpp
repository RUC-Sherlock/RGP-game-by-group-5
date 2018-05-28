#include "live_player.h"
#include <cmath>

void Live_player::setdpoint()
{
    _dx=_destination.x()-getObj_locationX();
    _dy=_destination.y()-getObj_locationY();
}

Live_player::Live_player(const QPoint &obj_location, const QPoint &rlocation, const QPoint &rheart, const int img_num, const char **dir_set,
       const int hurtable_range, const int attack_range, const int MAXHP, int speed, const QPoint &des):
    Abstract_obj(obj_location,rlocation,img_num,dir_set),
    _HP(MAXHP),_MAXHP(MAXHP),_hurtable_range(hurtable_range),_attack_range(attack_range),_speed(speed),_HPBar_length(_MAXHP*_HPBar_elastic),
    _heart(obj_location-rlocation+rheart),_obj_rheart(rheart-rlocation),_destination(des)
{
    setdpoint();
}

void Live_player::setDestination(const QPoint &des)
{
    _destination=des;
    setdpoint();
}

void Live_player::setObj_location(const QPoint &obj_location)
{
    Abstract_obj::setObj_location(obj_location);
    _heart=_obj_rheart+getObj_location();
    setdpoint();
}

int Live_player::HeartDistanceWith(const Abstract_obj & obj)const
{
    int dx=this->_heart.x()-obj.getObj_locationX();
    int dy=this->_heart.y()-obj.getObj_locationY();
    return sqrt(dx*dx+dy*dy);
}

bool Live_player::inAttack_range(const Live_player &obj) const
{
    return _attack_range>=ObjDistanceWith(obj);
}


void Live_player::move(void)
{
    int distance=(int)(sqrt(_dx*_dx+_dy*_dy)+0.01);
    //如果不重合，一定distance>=1
    if(distance<=_speed)
    {
        setObj_location(_destination);
        return;
    }
    //此时distance<_speed
    int xfoot,yfoot;
    if(_dx==0) xfoot=0;
    else {
        xfoot=(_speed*_dx)/distance;
    }
    if(_dy==0) yfoot=0;
    else {
        yfoot=(_speed*_dy)/distance;
    }
    setObj_location(getObj_location()+QPoint(xfoot,yfoot));
}


bool Live_player::hurtedBy(Thrown_obj & obj)
{
    if(_hurtable_range<HeartDistanceWith(obj))
    {
        return false;
    }
    else
    {
        obj.deleteIt();
        return true;
    }
}

bool Live_player::inMyLeft(const Live_player & obj)const
{
    return obj.getObj_locationX()<getObj_locationX();
}


void Live_player::drawImage(QPainter &p,int index)
{
    Abstract_obj::drawImage(p,index);
    if(_HP<=0)  return;
    QPoint HPBar_TopLeft=HPBar_center()-QPoint(_HPBar_length*0.5,_HPBar_height);
    p.setBrush(Qt::red);
    p.drawRect(HPBar_TopLeft.x(),HPBar_TopLeft.y(),_HP*_HPBar_elastic,_HPBar_height);
    p.save();
    p.restore();
}


void Live_player::reduceHP(int amount)
{
    _HP-=amount;
    if(_HP<0) _HP=0;
}
