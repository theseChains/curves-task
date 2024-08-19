#include "Helix.h"

#include <cmath>
#include <numbers>
#include <stdexcept>

namespace cadex
{
Helix::Helix(double radius, double step) : m_radius{ radius }, m_step{ step }
{
    if (radius < 0.0)
    {
        throw std::invalid_argument{
            "cadex::Helix::Helix(double, double): radius must be greater than 0"
        };
    }
}

Point3D Helix::getPoint(double t) const
{
    return { m_radius * std::cos(t), m_radius * std::sin(t),
             m_step * t / (2 * std::numbers::pi) };
}

Point3D Helix::getDerivative(double t) const
{
    return { -m_radius * std::sin(t), m_radius * std::cos(t),
             m_step / (2 * std::numbers::pi) };
}

double Helix::getRadius() const
{
    return m_radius;
}

double Helix::getStep() const
{
    return m_step;
}

void Helix::setRadius(double radius)
{
    m_radius = radius;
}

void Helix::setStep(double step)
{
    m_step = step;
}
}
