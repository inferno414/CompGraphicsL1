#include "MMatrix.h"

MMatrix::MMatrix(){
    arr = new double*[NSIZE];
    for(int i=0; i<NSIZE ;i++){
        arr[i] = new double[NSIZE];
        for(int j = 0; j< NSIZE; j++)
            arr[i][j] = 0.0;
    }
}

MMatrix::MMatrix(const MMatrix & other)
{
    arr = new double*[NSIZE];
    for(int i=0; i<NSIZE ;i++){
        arr[i] = new double[NSIZE];
        for(int j = 0; j< NSIZE; j++)
            arr[i][j] = other.arr[i][j]; //ikk
    }
}

MMatrix::~MMatrix()
{
    for(int i=0;i<NSIZE;i++)
        delete [] arr[i];
    delete [] arr;
}

void MMatrix::rotY(int angle){
    arr[0][0] = 1;
    arr[1][1] = arr[2][2] = cos(angle*COEF);
    arr[2][1] = sin(angle*COEF);
    arr[1][2] = -arr[2][1];
    arr[3][3] = 1;
}

void MMatrix::rotX(int angle){
    arr[1][1] = 1;
    arr[0][0] = arr[2][2] = cos(angle*COEF);
    arr[2][0] = sin(angle*COEF);
    arr[0][2] = -arr[2][0];
    arr[3][3] = 1;
}

void MMatrix::scale(double a, double b, double c){
    arr[0][0] = a;
    arr[1][1] = b;
    arr[2][2] = c;
    arr[3][3] = 1;
}

void MMatrix::move(double a, double b, double c)
{
    arr[0][2]=a;
    arr[1][2]=b;
    arr[2][2]=c;
    arr[3][3]=1;
}
MMatrix MMatrix::operator=(const MMatrix & other)
{
    if (&other != this){
        double **narr = new double*[NSIZE];
        for(int i=0; i<NSIZE ;i++){
            narr[i] = new double[NSIZE];
            for(int j = 0; j< NSIZE; j++)
                narr[i][j] = other.arr[i][j];
        }
        for(int i=0;i<NSIZE;i++)
            delete [] arr[i];
        delete [] arr;
        arr = narr;
    }
    return *this;
}

MMatrix operator*(MMatrix & MA, MMatrix & MB){
    MMatrix res;
    for(int i=0; i<NSIZE; i++)
        for(int j=0; j<NSIZE; j++){
            res.arr[i][j]=0;
            for(int k=0; k<NSIZE; k++)
                res.arr[i][j]+=MA.arr[i][k]*MB.arr[k][j];
        }
    return res;
}

MPoint operator*(MMatrix & M, MPoint & other)
{
    MPoint res;
    res.x = other.x*M.arr[0][0]+other.y*M.arr[0][1]+other.z*M.arr[0][2]+other.w*M.arr[0][3];
    res.y = other.x*M.arr[1][0]+other.y*M.arr[1][1]+other.z*M.arr[1][2]+other.w*M.arr[1][3];
    res.z = other.x*M.arr[2][0]+other.y*M.arr[2][1]+other.z*M.arr[2][2]+other.w*M.arr[2][3];
    res.w = other.x*M.arr[3][0]+other.y*M.arr[3][1]+other.z*M.arr[3][2]+other.w*M.arr[3][3];
    return res;
}


