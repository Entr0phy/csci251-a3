#include "Point2D.h"
#include "Line2D.h"
#include "Point3D.h"
#include "Line3D.h"
#include <iostream>

int main()
{
    Point3D test1 = Point3D(-99, -99, -99);
    Point3D test2 = Point3D(-999, -999, -999);
    Line3D test = Line3D(test1, test2);
    std::cout << test.getScalarValue();
    return 0;
}