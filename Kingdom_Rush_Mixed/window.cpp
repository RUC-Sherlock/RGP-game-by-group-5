#include "window.h"
#include "ui_window.h"
#include <QPainter>
#include <QTimer>

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
        player.react(Princess::Lstand);
    else
        player.react(Princess::Rstand);
}


void Window::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        player.setDestination(event->pos());
        player.react(Princess::Move);
    }
}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(rect(),_background);
    player.draw(painter);
    if(sqrt(pow(player.getObj_locationX()-stone1.getObj_locationX(),2.0)+pow(player.getObj_locationY()-stone1.getObj_locationY(),2.0))<=stone1.getAttack_range())
        stone1.react(Enermy_far::Lattack);
    else
        stone1.react(Enermy_far::Lwalk);
    stone1.draw(painter);
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
        player.react(Princess::Longattack);
}
Window::~Window()
{
    delete ui;
}
