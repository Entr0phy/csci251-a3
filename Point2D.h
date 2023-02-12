class Point2D
{
protected:
    int x;
    int y;
    double distFrOrigin;

public:
    // accessor methods
    int getX();
    int getY();
    double getDistFrOrigin();
    double getScalarValue();

    // mutator method
    void setX(int x);
    void setY(int y);
    void setDistFrOrigin(double origin);
};