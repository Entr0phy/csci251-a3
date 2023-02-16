#include "Point3D.h"
#include <cmath>

// operator overloading
std::ostream &operator<<(std::ostream &os, const Point3D &pt)
{
    os << "[" << std::setw(4) << pt.x << "," << std::setw(4) << pt.y << std::setw(4) << pt.z << "]   " << std::fixed << std::setprecision(3) << pt.distFrOrigin << std::endl;
    return os;
}

bool operator==(const Point3D &pt1, const Point3D &pt2)
{
    return pt1.x == pt2.x && pt1.y == pt2.y && pt1.z == pt2.z;
}

bool operator<(const Point3D &a, const Point3D &b)
{
    // if criteria is x-ordinate, compare x, if both are the same compare y if both are the same
    //  again compare z
    if (a.sortCrit == "x-ordinate")
    {
        if (a.x == b.x && a.y == b.y)
            return a.z < b.z;
        else if (a.x == b.x)
        {
            return a.y < b.y;
        }
        else
            return a.x < b.x;
    }

    else if (a.sortCrit == "y-ordinate")
    {
        if (a.x == b.x && a.y == b.y)
            return a.z < b.z;
        else if (a.y == b.y)
            return a.x < b.x;
        else
            return a.y < b.y;
    }

    else if (a.sortCrit == "z-ordinate")
    {
        if (a.z == b.z && a.y == b.y)
            return a.x < b.x;
        else if (a.z == b.z)
            return a.y < b.y;
        else
            return a.z < b.z;
    }

    else
    {
        return a.distFrOrigin < b.distFrOrigin;
    }
}

bool operator>(const Point3D &a, const Point3D &b)
{
    // if criteria is x-ordinate, compare x, if both are the same compare y if both are the same
    //  again compare z
    if (a.sortCrit == "x-ordinate")
    {
        if (a.x == b.x && a.y == b.y)
            return a.z > b.z;
        else if (a.x == b.x)
        {
            return a.y > b.y;
        }
        else
            return a.x > b.x;
    }

    else if (a.sortCrit == "y-ordinate")
    {
        if (a.x == b.x && a.y == b.y)
            return a.z > b.z;
        else if (a.y == b.y)
            return a.x > b.x;
        else
            return a.y > b.y;
    }

    else if (a.sortCrit == "z-ordinate")
    {
        if (a.z == b.z && a.y == b.y)
            return a.x > b.x;
        else if (a.z == b.z)
            return a.y > b.y;
        else
            return a.z > b.z;
    }

    else
    {
        return a.distFrOrigin > b.distFrOrigin;
    }
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
