#include "Point2D.h"
#include <cmath>

// operator overloading
std::ostream &operator<<(std::ostream &os, const Point2D &pt)
{
    os << "[" << std::setw(4) << pt.x << "," << std::setw(4) << pt.y << "]   " << std::fixed << std::setprecision(3) << pt.distFrOrigin << std::endl;
    return os;
}

bool operator==(Point2D &a, Point2D &b)
{
    return a.getX() == b.getX() && a.getY() == b.getY();
}

bool operator>(Point2D &a, Point2D &b)
{
    // if sort criteria is x -ordinate, is both x is the same compare y else compare x
    if (a.sortCrit == "x-ordinate")
    {
        if (a.getX() == b.getX())
            return a.getY() > b.getY();
        return a.getX() > b.getX();
    }
    else if (a.sortCrit == "y-ordinate")
    {
        if (a.getY() == b.getY())
            return a.getX() > b.getX();
        return a.getY() > b.getY();
    }
    else
    {
        return a.getScalarValue() > b.getScalarValue();
    }
}

bool operator<(Point2D &a, Point2D &b)
{
    // if sort criteria is x -ordinate, if both x is the same compare y else compare x
    if (a.sortCrit == "x-ordinate")
    {
        if (a.getX() == b.getX())
            return a.getY() < b.getY();
        return a.getX() < b.getX();
    }

    // if sort criteria is y-ordinate, if both y is the same compare x else compare y
    else if (a.sortCrit == "y-ordinate")
    {
        if (a.getY() == b.getY())
            return a.getX() < b.getX();
        return a.getY() < b.getY();
    }

    // compare the scalar value
    else
    {
        return a.getScalarValue() < b.getScalarValue();
    }
}

// default constructor
Point2D::Point2D()
{
    Point2D::setX(0);
    Point2D::setY(0);
    Point2D::setDistFrOrigin();
};

Point2D::Point2D(int x, int y)
{
    Point2D::setX(x);
    Point2D::setY(y);
    Point2D::setDistFrOrigin();
}

// accessor method
int Point2D::getX()
{
    return this->x;
}

int Point2D::getY()
{
    return this->y;
}

double Point2D::getScalarValue()
{
    return this->distFrOrigin;
}

std::string Point2D::getSortCrit()
{
    return this->sortCrit;
}
// mutator methods

void Point2D::setX(int x)
{
    this->x = x;
}

void Point2D::setY(int y)
{
    this->y = y;
}

void Point2D::setDistFrOrigin()
{
    int xVal = Point2D::getX() * Point2D::getX();
    int yVal = Point2D::getY() * Point2D::getY();
    this->distFrOrigin = std::sqrt(xVal + yVal);
}

void Point2D::setSortCrit(std::string sortCrit)
{
    this->sortCrit = sortCrit;
}