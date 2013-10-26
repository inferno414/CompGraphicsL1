#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include<QMouseEvent>
#include<cmath>
#include "MMatrix.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //setMouseTracking(true);
    A=10;
    D=30;
    E=0;
    R=3;
    dt=0.01;
    ui->horizontalSlider->setValue(A);
    ui->horizontalSlider_2->setValue(D);
    ui->horizontalSlider_4->setValue(R);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    Mx = e->x();
    My = e->y();
}

void Widget::paintEvent(QPaintEvent *e)
{
    double ox=width()/2, oy = height()/2;
    double scl = (width()+height())*0.001/2;
    QPainter painter(this);
    painter.setPen(QColor(150,70,160));
    MPoint p1,p2;
    MMatrix MRX,MRY,MS,MM;
    MRX.rotX(Mx);
    MRY.rotY(My);
    MS.scale(scl, scl, scl);
    MM.move(oy,ox,1);
    MMatrix MRE = MRY*MRX;
    MRE = MRE*MS;
    p1 = func(0);
    p1 = MRE*p1;
    for(double t = 0.01; t < 50;){
        t += dt;
        p2 = func(t);
        p2 = MRE*p2;
        painter.drawLine(int(p1.x+ox),int(p1.y+oy),int(p2.x+ox),int(p2.y+oy));
        p1=p2;
    }
    update();
}

MPoint Widget::func(double t)
{
    MPoint res;
    res.x=A*t*cos(t)+D*cos(E*t);
    res.y=A*t*sin(t)+D*sin(E*t);
    double n = 10*R*R-res.x*res.x-res.y*res.y;
    if (n < 0)
        res.z=-pow(-n,1/2.);
    else
        res.z=pow(n,1/2.);
    return res;
}

void Widget::on_pushButton_clicked()
{
    close();
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    Widget::A=value;
}

void Widget::on_horizontalSlider_2_valueChanged(int value)
{
    Widget::D=value;
}

void Widget::on_horizontalSlider_3_valueChanged(int value)
{
    Widget::E=value;
}

void Widget::on_horizontalSlider_4_valueChanged(int value)
{
    Widget::R=value;
}

void Widget::on_doubleSpinBox_valueChanged(double arg1)
{
    dt=arg1;
}
