#include "Ellipse.h"

#include <cmath>
#include <stdexcept>

namespace cadex
{
Ellipse::Ellipse(double xRadius, double yRadius)
    : m_xRadius{ xRadius }, m_yRadius{ yRadius }
{
    if (xRadius < 0.0 || yRadius < 0.0)
    {
        throw std::invalid_argument{ "cadex::Ellipse::Ellipse(double, double): xRadius and yRadius must be greater than 0" };
    }
}

Point3D Ellipse::getPoint(double t) const
{
    return { m_xRadius * std::cos(t), m_yRadius * std::sin(t), 0.0 };
}

Point3D Ellipse::getDerivative(double t) const
{
    return { -m_xRadius * std::sin(t), m_yRadius * std::cos(t), 0.0 };
}

double Ellipse::getXRadius() const
{
    return m_xRadius;
}

double Ellipse::getYRadius() const
{
    return m_yRadius;
}

void Ellipse::setXRadius(double xRadius)
{
    m_xRadius = xRadius;
}

void Ellipse::setYRadius(double yRadius)
{
    m_yRadius = yRadius;
}
}
