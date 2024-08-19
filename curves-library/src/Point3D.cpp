#include "Point3D.h"

namespace cadex
{
Point3D::Point3D(double x, double y, double z) : m_x{ x }, m_y{ y }, m_z{ z }
{
}

double Point3D::getX() const
{
    return m_x;
}

double Point3D::getY() const
{
    return m_y;
}

double Point3D::getZ() const
{
    return m_z;
}

void Point3D::setX(double x)
{
    m_x = x;
}

void Point3D::setY(double y)
{
    m_y = y;
}

void Point3D::setZ(double z)
{
    m_z = z;
}

std::ostream& operator<<(std::ostream& out, const Point3D& point)
{
    out << '[' << point.getX() << ", " << point.getY() << ", " << point.getZ()
        << ']';

    return out;
}
}
