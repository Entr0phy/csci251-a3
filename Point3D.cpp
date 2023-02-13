#include "Point3D.h"
#include "Point2D.h"
#include <cmath>

bool operator==(const Point3D &pt1, const Point3D &pt2)
{
    return pt1.x == pt2.x && pt1.y == pt2.y && pt1.z == pt2.z;
}
Point3D::Point3D(){};
Point3D::Point3D(int x, int y, int z) : Point2D(x, y)
{
    Point3D::setZ(z);
    Point3D::setDistFrOrigin();
}

// accessor methods
int Point3D::getZ()
{
    return this->z;
}

// mutator method
void Point3D::setZ(int z)
{
    this->z = z;
}

void Point3D::setDistFrOrigin()
{
    int xVal = std::pow(Point3D::getX(), 2);
    int yVal = std::pow(Point3D::getY(), 2);
    int zVal = std::pow(Point3D::getZ(), 2);
    this->distFrOrigin = std::sqrt(xVal + yVal + zVal);
}