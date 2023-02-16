#ifndef POINT3D_H
#define POINT3D_H
#include "Point2D.h"
#include <string>
#include <iostream>
#include <iomanip>
class Point3D : public Point2D
{
    friend std::ostream &operator<<(std::ostream &, const Point3D &);
    friend bool operator==(const Point3D &, const Point3D &);
    friend bool operator>(const Point3D &, const Point3D &);
    friend bool operator<(const Point3D &, const Point3D &);

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