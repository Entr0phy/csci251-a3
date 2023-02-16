#ifndef POINT2D_H
#define POINT2D_H
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
class Point2D
{
    friend std::ostream &operator<<(std::ostream &, const Point2D &);
    friend bool operator==(Point2D &a, Point2D &b);
    friend bool operator>(Point2D &a, Point2D &b);
    friend bool operator<(Point2D &a, Point2D &b);

protected:
    int x;
    int y;
    double distFrOrigin;
    std::string sortCrit;

public:
    // accessor methods
    Point2D();
    Point2D(int x, int y);
    int getX();
    int getY();
    double getScalarValue();
    std::string getSortCrit();

    // mutator method
    void setX(int x);
    void setY(int y);
    void setDistFrOrigin();
    void setSortCrit(std::string sortCrit);
};
#endif