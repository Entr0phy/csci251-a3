#include "Line3D.h"
#include "Line2D.h"
#include <cmath>
#include <iostream>

// operator overloading
std::ostream &operator<<(std::ostream &os, Line3D &line)
{
    os << "[" << std::setw(4) << line.getPt1().getX() << "," << std::setw(4)
       << line.getPt1().getY() << std::setw(4) << line.getPt1().getZ() << "]   "
       << "[" << std::setw(4) << line.getPt2().getX() << "," << std::setw(4) << line.getPt2().getY()
       << std::setw(4) << line.getPt2().getZ()
       << "]   " << std::fixed << std::setprecision(3) << line.getScalarValue() << std::endl;
    return os;
}

bool operator==(Line3D &a, Line3D &b)
{
    bool xVal = a.getPt1().getX() == b.getPt1().getX() && a.getPt2().getX() == b.getPt2().getX();
    bool yVal = a.getPt1().getY() == b.getPt1().getY() && a.getPt2().getY() == b.getPt2().getY();
    bool ZVal = a.getPt1().getZ() == b.getPt1().getZ() && a.getPt2().getZ() == b.getPt2().getZ();
    return xVal == true && yVal == true && ZVal == true;
}

bool operator>(Line3D &line1, Line3D &line2)
{
    if (line1.sortCrit == "pt1")
    {
        if (line1.getPt1().getX() == line2.getPt1().getX())
            return line1.getPt1().getY() > line2.getPt1().getY();
        return line1.getPt1().getX() > line2.getPt1().getX();
    }

    else if (line1.sortCrit == "pt2")
    {
        if (line1.getPt2().getX() == line2.getPt2().getX())
            return line1.getPt2().getY() > line2.getPt2().getY();
        return line1.getPt2().getX() > line2.getPt2().getX();
    }
    else
        return line1.getScalarValue() > line2.getScalarValue();
}

bool operator<(Line3D &line1, Line3D &line2)
{
    if (line1.sortCrit == "pt1")
    {
        if (line1.getPt1().getX() == line2.getPt1().getX())
            return line1.getPt1().getY() < line2.getPt1().getY();
        return line1.getPt1().getX() < line2.getPt1().getX();
    }

    else if (line1.sortCrit == "pt2")
    {
        if (line1.getPt2().getX() == line2.getPt2().getX())
            return line1.getPt2().getY() < line2.getPt2().getY();
        return line1.getPt2().getX() < line2.getPt2().getX();
    }
    else
        return line1.getScalarValue() < line2.getScalarValue();
}
Line3D::Line3D(){};

Line3D::Line3D(Point3D pt1, Point3D pt2)
{
    Line3D::setPt1(pt1);
    Line3D::setPt2(pt2);
    Line3D::setLength();
};

// accessor methods
Point3D Line3D::getPt1()
{
    return this->pt1;
}

Point3D Line3D::getPt2()
{
    return this->pt2;
}

// mutator method
void Line3D::setPt1(Point3D pt1)
{
    this->pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2)
{
    this->pt2 = pt2;
}

void Line3D::setLength()
{
    double xPointer = std::pow((Line3D::getPt1().getX() - Line3D::getPt2().getX()), 2);
    double yPointer = std::pow((Line3D::getPt1().getY() - Line3D::getPt2().getY()), 2);
    double zPointer = std::pow((Line3D::getPt1().getZ() - Line3D::getPt2().getZ()), 2);
    this->length = std::sqrt(xPointer + yPointer + zPointer);
}