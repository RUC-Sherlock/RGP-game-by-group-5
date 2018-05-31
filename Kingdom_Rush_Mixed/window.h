#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QImage>
#include <forward_list>
#include "constant.h"
#include "enemy_monster.h"
#include "princess.h"
#include "iceball.h"
#include "enemy_wolf.h"

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event){update();}
private:
    Ui::Window *ui;
    Princess princess;
    std::forward_list<Live_player *> enemy;
    //std::forward_list<Live_player *> guard;
    //std::forward_list<Thrown_obj *> enemy_obj;
    std::forward_list<Thrown_obj *> guard_obj;
    QImage _background;
    QPoint mousepos;
private slots:
    void emit_iceball(const QPoint &);
    //void emit_others(Signal type,const QPoint &obj_location,const QPoint &heart);
};

#endif // WINDOW_H
