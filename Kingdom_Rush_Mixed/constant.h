#ifndef CONSTANT_H
#define CONSTANT_H

#include <QPoint>
enum class Signal{};
enum class Command{Lstand,Rstand,Longattack,Move,Lwalk,Lattack,Rattack};
enum Route{map1_1,map1_2,map1_3,map2_1,map2_2,map3_1,map3_2,map3_3,map3_4};

const QPoint destination[9][4]=
{{QPoint(1152,228),QPoint(950,430),QPoint(293,427),QPoint(0,562)},
 {QPoint(1020,497),QPoint(760,497),QPoint(380,497),QPoint(0,497)},
 {QPoint(985,625),QPoint(776,625),QPoint(385,625),QPoint(0,582)},
 {QPoint(918,322),QPoint(696,382),QPoint(172,327),QPoint(0,397)},
 {QPoint(995,716),QPoint(644,812),QPoint(301,728),QPoint(0,741)},
 {QPoint(445,190),QPoint(426,411),QPoint(205,545),QPoint(0,520)},
 {QPoint(882,266),QPoint(834,441),QPoint(432,412),QPoint(0,515)},
 {QPoint(911,624),QPoint(847,468),QPoint(442,422),QPoint(0,533)},
 {QPoint(900,844),QPoint(630,683),QPoint(605,378),QPoint(0,522)}
};


#endif // CONSTANT_H
