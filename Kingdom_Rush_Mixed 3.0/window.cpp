#include "window.h"
#include "ui_window.h"
#include <QPainter>
#include <QTimer>
#include "iceball.h"
#include <iostream>

template<typename T>
static void clear(std::forward_list<T> &mylist)
{
    auto prev=mylist.before_begin();
    auto curr=mylist.begin();
    while(curr!=mylist.end())
    {
        if((*curr)->isDeletable())
        {
            delete (*curr);
            curr=mylist.erase_after(prev);
        }
        else
        {
            prev=curr;
            curr++;
        }
    }
}

template<typename T>
static void deleteIt(std::forward_list<T> &mylist)
{
    for(auto it=mylist.begin();it!=mylist.end();++it)
    {
        delete (*it);
    }
}


Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window),princess(54,531),
    _background(":/background/image/map/1.png")
{
    ui->setupUi(this);
    setMouseTracking(true);
    for(int i=0;i<3;i++)
    {
    enemy.push_front(new Enemy_monster(startposition[i],i));
    }
    //enemy.push_front(new Enemy_wolf(1156,490));
    QObject::startTimer(25);
    connect(&princess,SIGNAL(iceball(QPoint)),this,SLOT(emit_iceball(QPoint)),Qt::UniqueConnection);
}

void Window::mouseMoveEvent(QMouseEvent *event)
{
    if(event->x()<princess.getObj_locationX())
        princess.react(Command::Lstand);
    else
        princess.react(Command::Rstand);
    mousepos=event->pos();
}

void Window::emit_iceball(const QPoint & location)
{
    if(location!=mousepos)
    guard_obj.push_front(new Iceball(location,mousepos));

}

void Window::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        princess.setDestination(event->pos());
        princess.react(Command::Move);
    }
}


void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(rect(),_background);
//处理部分
    for(auto i=enemy.begin();i !=enemy.end();++i)
    {
        (*i)->process(princess);
        for(auto j=guard_obj.begin();j!=guard_obj.end();++j)
        {
            (*i)->hurtedBy(**j);
        }
    }
//删除部分
    clear(enemy);
    clear(guard_obj);
//排序部分
//画画部分
    princess.draw(painter);
    for(auto it=enemy.begin();it!=enemy.end();++it)
    {
        (*it)->draw(painter);
    }
    for(auto it=guard_obj.begin();it!=guard_obj.end();++it)
    {
        (*it)->draw(painter);
    }
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
        princess.react(Command::Longattack);
}

Window::~Window()
{
    delete ui;
    deleteIt(enemy);
    deleteIt(guard_obj);
}
