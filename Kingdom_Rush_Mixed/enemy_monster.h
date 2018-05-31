#ifndef ENERMY_MONSTER_H
#define ENERMY_MONSTER_H

#include "constant.h"
#include "live_player.h"
#include <QPoint>

class Enemy_monster : public Live_player
{
    Q_OBJECT
signals:
    void attack(int amount);
public:
    Enemy_monster(int route);
    void react(Command cmd);
    void draw(QPainter &p);
    bool hurtedBy(Thrown_obj &obj);
    bool isWalking(void)const;
    void process(const Live_player & obj);
    ~Enemy_monster(){}
private:
    enum Condition{l_walk1_1,l_walk1_2,l_walk2_1,l_walk2_2,l_walk3_1,l_walk3_2,l_walk4_1,l_walk4_2,l_walk5_1,l_walk5_2,l_walk6_1,l_walk6_2,l_walk7_1,l_walk7_2,l_walk8_1,l_walk8_2,l_walk9_1,l_walk9_2,l_walk10_1,l_walk10_2,l_walk11_1,l_walk11_2,l_walk12_1,l_walk12_2,
                   l_attack1_1,l_attack1_2,l_attack1_3,l_attack2_1,l_attack2_2,l_attack2_3,l_attack3_1,l_attack3_2,l_attack3_3,l_attack4_1,l_attack4_2,l_attack4_3,l_attack5_1,l_attack5_2,l_attack5_3,l_attack6_1,l_attack6_2,l_attack6_3,
                   r_attack1_1,r_attack1_2,r_attack1_3,r_attack2_1,r_attack2_2,r_attack2_3,r_attack3_1,r_attack3_2,r_attack3_3,r_attack4_1,r_attack4_2,r_attack4_3,r_attack5_1,r_attack5_2,r_attack5_3,r_attack6_1,r_attack6_2,r_attack6_3,
                   death1_1,death1_2,death1_3,death2_1,death2_2,death2_3,death3_1,death3_2,death3_3,death4_1,death4_2,death4_3,death5_1,death5_2,death5_3,death6_1,death6_2,death6_3,death7_1,death7_2,death7_3};
    Condition _condition;
    int point_destination;//标记下一个要去的点是第几个。针对destination数组中的列数，0-3
    int _sleep;
    int _route;
};

#endif // ENERMY_FAR_H
