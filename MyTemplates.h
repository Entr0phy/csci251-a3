#include <cstdlib>
template <typename T>
double scalar_difference(T a, T b)
{
    return abs(a.getScalarValue() - b.getScalarValue());
}

template <typename T>
bool equals(T pt1, T pt2)
{
    return pt1 == pt2;
};

template <typename T>
bool ASC(T pt1, T pt2)
{
    return pt1 < pt2;
}

template <typename T>
bool DSC(T pt1, T pt2)
{
    return pt1 > pt2;
}