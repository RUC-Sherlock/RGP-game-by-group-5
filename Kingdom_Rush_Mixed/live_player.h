#ifndef LIVE_PLAYER_H
#define LIVE_PLAYER_H

#include "constant.h"
#include "thrown_obj.h"

class Thrown_obj;

class Live_player:public Abstract_obj
{
    Q_OBJECT
private:
    int _HP;
    int _MAXHP;
    int _hurtable_range;
    int _attack_range;
    int _dx;
    int _dy;
    int _speed;
    static const int _HPBar_height=5;
    constexpr static const double _HPBar_elastic=0.25;
    int _HPBar_length;
    QPoint _heart;
    QPoint _obj_rheart;//心相对于_obj_location的坐标
    QPoint _destination;
    void setdpoint();
public:
    Live_player(const QPoint & obj_location,const QPoint & rlocation,const QPoint & rheart,const int img_num,const char **dir_set,
           const int hurtable_range,const int attack_range,const int MAXHP,int speed=0,const QPoint & des=QPoint());
    const QPoint & getHeart(void)const {return _heart;}
    int getHP(void)const {return _HP;}
    int getMAXHP(void)const {return _MAXHP;}
    int getDx(void)const {return _dx;}
    int getDy(void) {return _dy;}
    int getSpeed(void) {return _speed;}
    int getHurtable_range(void)const {return _hurtable_range;}
    int getAttack_range(void)const {return _attack_range;}
    int getDestinationX(void)const {return _destination.x();}
    int getDestinationY(void)const {return _destination.y();}
    int HeartDistanceWith(const Abstract_obj & obj)const;
    bool inMyLeft(const Live_player & obj)const;
    bool inMyRight(const Live_player & obj)const {return !inMyLeft(obj);}
    bool inAttack_range(const Live_player & obj)const;
    void setDestination(const QPoint & des);
    virtual void draw(QPainter &p)=0;
    virtual bool hurtedBy(Thrown_obj & obj)=0;
    virtual void process(const Live_player & obj)=0;
    virtual ~Live_player(){}
protected:
    void setMAXHP(int MAXHP) {_MAXHP=MAXHP;}
    void setHurtable_range(int hurtable_range){_hurtable_range=hurtable_range;}
    void setAttack_range(int attack_range){_attack_range=attack_range;}
    void setHP(int HP) {_HP=HP;}
    void setSpeed(int speed) {_speed=speed;}
    virtual void drawImage(QPainter &p,int index);
    virtual void setObj_location(const QPoint & obj_location);
    virtual void move();
protected slots:
    void reduceHP(int amount);
};


/*class pLive_player
{
private:
    Live_player * _p;
public:
    pLive_player(Live_player * p):_p(p){}
    pLive_player(const pLive_player & obj):_p(new Live_player(*obj.use())){}
    const pLive_player & operator =(const pLive_player & obj)
    {
        _p=new Live_player(*obj.use());
        return *this;
    }
    Live_player * use(void)const {return _p;}
    ~pLive_player(){delete _p;}
};
*/
#endif // LIVE_PLAYER_H
