#include "window.h"
#include "ui_window.h"
#include "constant.h"
#include <QPainter>
#include <QTimer>
#include <iostream>

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window),player(0,0),stone1(1200,246),//可以以后根据每一个route写一个点坐标
    _background(":/background/image/map/1.png")
{
    ui->setupUi(this);
    setMouseTracking(true);
    QObject::startTimer(20);
    //connect()
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
    if(event->x()<player.getObj_locationX())
        player.react(Command::Lstand);
    else
        player.react(Command::Rstand);
}


void Window::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        player.setDestination(event->pos());
        player.react(Command::Move);
    }
}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(rect(),_background);
    player.draw(painter);
    if(player.ObjDistanceWith(stone1)<=stone1.getAttack_range())
    {
        if(player.getObj_locationX()>=stone1.getObj_locationX())
        {
            stone1.react(Command::Rattack);
            std::cout<<"Rattack";
        }
        else
        {
            stone1.react(Command::Lattack);
            std::cout<<"Lattack"<<player.getDx()-stone1.getDx();
        }
    }
    else
        stone1.react(Command::Lwalk);
    stone1.draw(painter);
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
        player.react(Command::Longattack);
}
Window::~Window()
{
    delete ui;
}
