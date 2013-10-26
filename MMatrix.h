#ifndef MMATRIX_H
#define MMATRIX_H
#include <cmath>

const int NSIZE = 4;
const double COEF = 0.005;

struct MPoint{
    double x,y,z,w;
};

class MMatrix{
private:
    double **arr;
public:
    MMatrix();
    MMatrix(const MMatrix &);
    ~MMatrix();

    void rotX(int angle);
    void rotY(int angle);
    void scale(double a, double b, double c);
    void move(double a, double b, double c);
    MMatrix operator=(const MMatrix &);

    friend MMatrix operator*(MMatrix &,MMatrix &);
    friend MPoint operator*(MMatrix &,MPoint &);


};



#endif // MMATRIX_H
