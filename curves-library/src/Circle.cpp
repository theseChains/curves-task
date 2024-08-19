#include "Circle.h"

#include <cmath>
#include <stdexcept>

namespace cadex
{
Circle::Circle(double radius) : m_radius{ radius }
{
    if (radius < 0.0)
    {
        throw std::invalid_argument{
            "cadex::Circle::Circle(double): radius must be greater than 0"
        };
    }
}

Point3D Circle::getPoint(double t) const
{
    return { m_radius * std::cos(t), m_radius * std::sin(t), 0.0 };
}

Point3D Circle::getDerivative(double t) const
{
    return { -m_radius * std::sin(t), m_radius * std::cos(t), 0.0 };
}

double Circle::getRadius() const
{
    return m_radius;
}

void Circle::setRadius(double radius)
{
    m_radius = radius;
}
}
