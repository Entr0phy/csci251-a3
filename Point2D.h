#ifndef POINT2D_H
#define POINT2D_H
class Point2D
{
protected:
    int x;
    int y;
    double distFrOrigin;

public:
    // accessor methods
    Point2D();
    Point2D(int x, int y);
    int getX();
    int getY();
    double getScalarValue();

    // mutator method
    void setX(int x);
    void setY(int y);
    void setDistFrOrigin();
};
#endif