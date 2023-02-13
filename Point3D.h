#ifndef POINT3D_H
#define POINT3D_H
#include "Point2D.h"

class Point3D : public Point2D
{
protected:
    int z;
    void setDistFrOrigin();

public:
    Point3D();
    Point3D(int x, int y, int z);
    int getZ();
    void setZ(int z);
};

#endif