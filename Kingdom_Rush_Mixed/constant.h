#ifndef CONSTANT_H
#define CONSTANT_H
#include <QPoint>
enum class Command{Lstand,Rstand,Longattack,Move,Lwalk,Lattack,Rattack,Death};
enum Route{map1_1,map1_2,map1_3,map2_1,map2_2,map3_1,map3_2,map3_3,map3_4};
enum Background{start,home,map1,map2,map3};

extern const QPoint destination[9][4];
extern const QPoint startposition[9];
extern const char *background[];

#endif // CONSTANT_H
