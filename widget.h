#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "MMatrix.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    double A,R,D,E,dt;
    int Mx,My;
    ~Widget();
    void paintEvent(QPaintEvent *);
    MPoint func(double t);

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_doubleSpinBox_valueChanged(double arg1);

protected:
    void mouseMoveEvent(QMouseEvent *);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
