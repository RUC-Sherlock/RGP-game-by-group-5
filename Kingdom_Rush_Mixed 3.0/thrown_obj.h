#ifndef THROWN_OBJ_H
#define THROWN_OBJ_H

#include "abstract_obj.h"
#include "live_player.h"
//注意：必须要保证传入的obj_location和heart坐标不同

class Thrown_obj : public Abstract_obj
{
    friend class Live_player;
private:
    int _dx;
    int _dy;
    int _speed;
    int _stepmax;// number of steps allowed
public:
    Thrown_obj(const QPoint & obj_location, const QPoint & rlocation, const QPoint & heart,
               const int img_num, const char **dir_set, const int speed, const int stepmax);
    virtual void draw(QPainter &p)=0;
    virtual ~Thrown_obj(){}
protected:
    void move(void);
};


/*class pThrown_obj
{
private:
    Thrown_obj * _p;
public:
    pThrown_obj(Thrown_obj * p):_p(p){}
    pThrown_obj(const pThrown_obj & obj):_p(new Thrown_obj(*obj.use())){}
    const pThrown_obj & operator =(const pThrown_obj & obj)
    {
        _p=new Thrown_obj(*obj.use());
        return *this;
    }
    Thrown_obj * use(void)const {return _p;}
    ~pThrown_obj(){delete _p;}
}*/

#endif // THROWN_OBJ_H
