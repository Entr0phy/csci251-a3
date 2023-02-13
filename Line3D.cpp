#include "Line3D.h"
#include "Line2D.h"
#include <cmath>
#include <iostream>

bool operator==(Line3D &a, Line3D &b)
{
    bool xVal = a.getPt1().getX() == b.getPt1().getX() && a.getPt2().getX() == b.getPt2().getX();
    bool yVal = a.getPt1().getY() == b.getPt1().getY() && a.getPt2().getY() == b.getPt2().getY();
    bool ZVal = a.getPt1().getZ() == b.getPt1().getZ() && a.getPt2().getZ() == b.getPt2().getZ();
    return xVal == true && yVal == true && ZVal == true;
}
Line3D::Line3D(){};

Line3D::Line3D(Point3D pt1, Point3D pt2)
{
    Line3D::setPt1(pt1);
    Line3D::setPt2(pt2);
    Line3D::setLength();
};

// accessor methods
Point3D Line3D::getPt1()
{
    return this->pt1;
}

Point3D Line3D::getPt2()
{
    return this->pt2;
}

// mutator method
void Line3D::setPt1(Point3D pt1)
{
    this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2)
{
    this->pt2 = pt2;
}

void Line3D::setLength()
{
    double xPointer = std::pow((Line3D::getPt1().getX() - Line3D::getPt2().getX()), 2);
    double yPointer = std::pow((Line3D::getPt1().getY() - Line3D::getPt2().getY()), 2);
    double zPointer = std::pow((Line3D::getPt1().getZ() - Line3D::getPt2().getZ()), 2);
    this->length = std::sqrt(xPointer + yPointer + zPointer);
}