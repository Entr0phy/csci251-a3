#include "Line2D.h"
#include <cmath>

bool operator==(Line2D &a, Line2D &b)
{
    bool xVal = a.getPt1().getX() == b.getPt1().getX() && a.getPt2().getX() == b.getPt2().getX();
    bool yVal = a.getPt1().getY() == b.getPt1().getY() && a.getPt2().getY() == b.getPt2().getY();
    return xVal == true && yVal == true;
}
// constructor
Line2D::Line2D(){};
Line2D::Line2D(Point2D pt1, Point2D pt2)
{
    Line2D::setPt1(pt1);
    Line2D::setPt2(pt2);
    Line2D::setLength();
}

// accessor methods
Point2D Line2D::getPt1()
{
    return this->pt1;
}

Point2D Line2D::getPt2()
{
    return this->pt2;
}

double Line2D::getScalarValue()
{
    return this->length;
}

// mutator method
void Line2D::setPt1(Point2D pt1)
{
    this->pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2)
{
    this->pt2 = pt2;
}

void Line2D::setLength()
{
    double xPointer = (Line2D::getPt1().getX() - Line2D::getPt2().getX()) * (Line2D::getPt1().getX() - Line2D::getPt2().getX());
    double yPointer = (Line2D::getPt1().getY() - Line2D::getPt2().getY()) * (Line2D::getPt1().getY() - Line2D::getPt2().getY());
    this->length = std::sqrt(xPointer + yPointer);
}