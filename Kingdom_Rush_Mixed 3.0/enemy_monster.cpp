#include "enemy_monster.h"
#include <QPoint>


static const char *dir_set[]=
    {":/enemy_monster/image/enemy_monster/l_walk (1).png",
     ":/enemy_monster/image/enemy_monster/l_walk (1).png",
     ":/enemy_monster/image/enemy_monster/l_walk (2).png",
     ":/enemy_monster/image/enemy_monster/l_walk (2).png",
     ":/enemy_monster/image/enemy_monster/l_walk (3).png",
     ":/enemy_monster/image/enemy_monster/l_walk (3).png",
     ":/enemy_monster/image/enemy_monster/l_walk (4).png",
     ":/enemy_monster/image/enemy_monster/l_walk (4).png",
     ":/enemy_monster/image/enemy_monster/l_walk (5).png",
     ":/enemy_monster/image/enemy_monster/l_walk (5).png",
     ":/enemy_monster/image/enemy_monster/l_walk (6).png",
     ":/enemy_monster/image/enemy_monster/l_walk (6).png",
     ":/enemy_monster/image/enemy_monster/l_walk (7).png",
     ":/enemy_monster/image/enemy_monster/l_walk (7).png",
     ":/enemy_monster/image/enemy_monster/l_walk (8).png",
     ":/enemy_monster/image/enemy_monster/l_walk (8).png",
     ":/enemy_monster/image/enemy_monster/l_walk (9).png",
     ":/enemy_monster/image/enemy_monster/l_walk (9).png",
     ":/enemy_monster/image/enemy_monster/l_walk (10).png",
     ":/enemy_monster/image/enemy_monster/l_walk (10).png",
     ":/enemy_monster/image/enemy_monster/l_walk (11).png",
     ":/enemy_monster/image/enemy_monster/l_walk (11).png",
     ":/enemy_monster/image/enemy_monster/l_walk (12).png",
     ":/enemy_monster/image/enemy_monster/l_walk (12).png",
     ":/enemy_monster/image/enemy_monster/l_attack (1).png",
     ":/enemy_monster/image/enemy_monster/l_attack (1).png",
     ":/enemy_monster/image/enemy_monster/l_attack (1).png",
     ":/enemy_monster/image/enemy_monster/l_attack (2).png",
     ":/enemy_monster/image/enemy_monster/l_attack (2).png",
     ":/enemy_monster/image/enemy_monster/l_attack (2).png",
     ":/enemy_monster/image/enemy_monster/l_attack (3).png",
     ":/enemy_monster/image/enemy_monster/l_attack (3).png",
     ":/enemy_monster/image/enemy_monster/l_attack (3).png",
     ":/enemy_monster/image/enemy_monster/l_attack (4).png",
     ":/enemy_monster/image/enemy_monster/l_attack (4).png",
     ":/enemy_monster/image/enemy_monster/l_attack (4).png",
     ":/enemy_monster/image/enemy_monster/l_attack5_1.png",
     ":/enemy_monster/image/enemy_monster/l_attack5_2.png",
     ":/enemy_monster/image/enemy_monster/l_attack5_3.png",
     ":/enemy_monster/image/enemy_monster/l_attack6_1.png",
     ":/enemy_monster/image/enemy_monster/l_attack6_2.png",
     ":/enemy_monster/image/enemy_monster/l_attack6_3.png",
     ":/enemy_monster/image/enemy_monster/r_attack1.png",
     ":/enemy_monster/image/enemy_monster/r_attack1.png",
     ":/enemy_monster/image/enemy_monster/r_attack1.png",
     ":/enemy_monster/image/enemy_monster/r_attack2.png",
     ":/enemy_monster/image/enemy_monster/r_attack2.png",
     ":/enemy_monster/image/enemy_monster/r_attack2.png",
     ":/enemy_monster/image/enemy_monster/r_attack3.png",
     ":/enemy_monster/image/enemy_monster/r_attack3.png",
     ":/enemy_monster/image/enemy_monster/r_attack3.png",
     ":/enemy_monster/image/enemy_monster/r_attack4.png",
     ":/enemy_monster/image/enemy_monster/r_attack4.png",
     ":/enemy_monster/image/enemy_monster/r_attack4.png",
     ":/enemy_monster/image/enemy_monster/r_attack5_1.png",
     ":/enemy_monster/image/enemy_monster/r_attack5_2.png",
     ":/enemy_monster/image/enemy_monster/r_attack5_3.png",
     ":/enemy_monster/image/enemy_monster/r_attack6_1.png",
     ":/enemy_monster/image/enemy_monster/r_attack6_2.png",
     ":/enemy_monster/image/enemy_monster/r_attack6_3.png",
     ":/enemy_monster/image/enemy_monster/death (1).png",
     ":/enemy_monster/image/enemy_monster/death (1).png",
     ":/enemy_monster/image/enemy_monster/death (1).png",
     ":/enemy_monster/image/enemy_monster/death (2).png",
     ":/enemy_monster/image/enemy_monster/death (2).png",
     ":/enemy_monster/image/enemy_monster/death (2).png",
     ":/enemy_monster/image/enemy_monster/death (3).png",
     ":/enemy_monster/image/enemy_monster/death (3).png",
     ":/enemy_monster/image/enemy_monster/death (3).png",
     ":/enemy_monster/image/enemy_monster/death (4).png",
     ":/enemy_monster/image/enemy_monster/death (4).png",
     ":/enemy_monster/image/enemy_monster/death (4).png",
     ":/enemy_monster/image/enemy_monster/death (5).png",
     ":/enemy_monster/image/enemy_monster/death (5).png",
     ":/enemy_monster/image/enemy_monster/death (5).png",
     ":/enemy_monster/image/enemy_monster/death (6).png",
     ":/enemy_monster/image/enemy_monster/death (6).png",
     ":/enemy_monster/image/enemy_monster/death (6).png",
     ":/enemy_monster/image/enemy_monster/death (7).png",
     ":/enemy_monster/image/enemy_monster/death (7).png",
     ":/enemy_monster/image/enemy_monster/death (7).png"
    };
static const QPoint rlocation=QPoint(106,106);
static const QPoint rheart=QPoint(102,68);
//图片大小为146*120
static const int hurtable_range=30;
static const int attack_range=150;//？瞎写的，再调
static const int MAXHP=300;//同瞎写
static const int img_num=81;
static const int speed=3;
static const QPoint des=destination[0][0];//?

Enemy_monster::Enemy_monster(int xpos, int ypos,int route):
    Live_player(QPoint(xpos,ypos),rlocation,rheart,img_num,dir_set,hurtable_range,attack_range,MAXHP,speed,des),
    _condition(l_walk1_1),point_destination(0),_sleep(0)
{
    _route=route;
    setDestination(destination[route][0]);
}

Enemy_monster::Enemy_monster(const QPoint & obj_location,int route):
    Live_player(obj_location,rlocation,rheart,img_num,dir_set,hurtable_range,attack_range,MAXHP,speed,des),
    _condition(l_walk1_1),point_destination(0),_sleep(0)
{
    _route=route;
    setDestination(destination[route][0]);
}


void Enemy_monster::process(const Live_player & obj)
{
    //在你自己的process里面私人定制你想要的处理方案
    //此时也未必需要react函数了
    //因为process是你自己的类的函数
    //在你自己的类里就都是你自己的东西
    //不需要像react考虑window.cpp和你的类的交互问题
    //你自己想抽取obj什么信息就提取
    //想判断什么就判断什么
    //想研发什么技能就研发什么技能
    //下面我还是把window.cpp里面你的处理方法搬到了这里
    //你甚至可以不需要react函数 直接根据obj和你的对象的关系
    //改变condition
    if(getHP()==0)
        react(Command::Death);
    if(inAttack_range(obj))
    {
        connect(this,SIGNAL(attack(int)),&obj,SLOT(reduceHP(int)),Qt::UniqueConnection);
        if(inMyLeft(obj))
            react(Command::Lattack);
        else react(Command::Rattack);
    }
    else
    {
        disconnect(this,SIGNAL(attack(int)),&obj,SLOT(reduceHP(int)));
        react(Command::Lwalk);
    }
}

void Enemy_monster::react(Command cmd)
{
    if(_sleep%2) return;
    switch(cmd){
        case Command::Lwalk:
            if(getHP()==0)break;
            if(_condition<l_walk12_2) _condition=Condition(1+_condition);
            else if(_condition>=l_attack1_1&&_condition<l_attack6_3)
                _condition=Condition(1+_condition);
            else if(_condition>=r_attack1_1&&_condition<r_attack6_3)
                _condition=Condition(1+_condition);
            else if(_condition==r_attack6_3||_condition==l_attack6_3||_condition==l_walk12_2)
                _condition=l_walk1_1;
            break;
        case Command::Lattack:
            if(getHP()==0)break;
            //if(!isStanding()) return;
            //冰女进入攻击范围后小兵先停下再进攻
            //移动中无法进攻
            if(_condition<l_attack1_1)
                _condition=l_attack1_1;
            else if(_condition>=l_attack1_1&&_condition<=l_attack6_3)
            {
                if(_condition>=l_attack1_1&&_condition<l_attack6_3)
                    _condition=Condition(1+_condition);
                else
                    _condition=l_attack1_1;
            }
            else if(_condition>=r_attack1_1&&_condition<=r_attack6_3)
            {
                if(_condition>=r_attack1_1&&_condition<r_attack6_3)
                    _condition=Condition(1+_condition);
                else
                    _condition=l_attack1_1;
            }
            break;
        case Command::Rattack:
            if(getHP()==0)break;
            if(_condition<l_attack1_1)
                _condition=r_attack1_1;
            else if(_condition>=r_attack1_1&&_condition<=r_attack6_3)
            {
                if(_condition>=r_attack1_1&&_condition<r_attack6_3)
                    _condition=Condition(1+_condition);
                else
                    _condition=r_attack1_1;
            }
            else if(_condition>=l_attack1_1&&_condition<=l_attack6_3)
            {
                if(_condition>=l_attack1_1&&_condition<l_attack6_3)
                    _condition=Condition(1+_condition);
                else
                    _condition=r_attack1_1;
            }
            break;
        case Command::Death:
            if(_condition<death1_1)
                _condition=death1_1;
            else if(_condition>=death1_1&&_condition<death7_3)
                _condition=Condition(1+_condition);
            else if(_condition==death7_3)
                deleteIt();
        default:
            break;
    }
}


void Enemy_monster::draw(QPainter &p)
{
    drawImage(p,_condition);
    _sleep=(_sleep+1)%16;
    if(isWalking())
    {
        int dx=getDx();
        int dy=getDy();
        if(dx==0&&dy==0)
        {
            //到达目的地
            if(point_destination<=2)
            {
                point_destination++;
                setDestination(destination[_route][point_destination]);
            }
        }
        if(_sleep%8) return;
        move();
    }

    else if(_condition==l_attack5_2||_condition==r_attack5_2)
    {
        emit attack(10);//50是一次攻击的掉血量
    }
    //注意弄清楚_condition满足什么状态发送信号比较合适
}

bool Enemy_monster::isWalking(void)const
{
    if(_condition>=l_walk1_1&&_condition<=l_walk12_2)
        return true;
    else
        return false;
}



bool Enemy_monster::hurtedBy(Thrown_obj &obj)
{
    if(!Live_player::hurtedBy(obj)) return false;
    else reduceHP(20);
    return true;
}


