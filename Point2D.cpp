#include "Point2D.h"
#include <cmath>
// default constructor
bool operator==(Point2D &a, Point2D &b)
{
    return a.getX() == b.getX() && a.getY() == b.getY();
}
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