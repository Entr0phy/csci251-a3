#include "Line2D.h"
#include <cmath>

// operator overloading
std::ostream &operator<<(std::ostream &os, Line2D &line)
{
    os << "[" << std::setw(4) << line.getPt1().getX() << "," << std::setw(4)
       << line.getPt1().getY() << "]   "
       << "[" << std::setw(4) << line.getPt2().getX() << "," << std::setw(4) << line.getPt2().getY()
       << "]   " << std::fixed << std::setprecision(3) << line.getScalarValue() << std::endl;
    return os;
}

bool operator==(Line2D &a, Line2D &b)
{
    bool xVal = a.getPt1().getX() == b.getPt1().getX() && a.getPt2().getX() == b.getPt2().getX();
    bool yVal = a.getPt1().getY() == b.getPt1().getY() && a.getPt2().getY() == b.getPt2().getY();
    return xVal == true && yVal == true;
}

bool operator>(Line2D &line1, Line2D &line2)
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

bool operator<(Line2D &line1, Line2D &line2)
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

void Line2D::setSortCrit(std::string sortCrit)
{
    this->sortCrit = sortCrit;
}