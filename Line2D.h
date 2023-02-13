#ifndef LINE2D_H
#define LINE2D_H
#include "Point2D.h"

class Line2D
{
private:
    Point2D pt1;
    Point2D pt2;

protected:
    double length;
    void setLength();

public:
    // constructor
    Line2D(Point2D pt1, Point2D pt2);
    Line2D();
    // accessor methods
    Point2D getPt1();
    Point2D getPt2();
    double getScalarValue();

    // mutator method
    void setPt1(Point2D pt1);
    void setPt2(Point2D pt2);
};

#endif