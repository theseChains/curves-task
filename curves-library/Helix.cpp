#include "Helix.h"

#include <cmath>

namespace cadex
{
Helix::Helix(double radius, double step) : m_radius{ radius }, m_step{ step }
{
}

Point3D Helix::getPoint(double t) const
{
    return { m_radius * std::cos(t), m_radius * std::sin(t), m_step * t };
}

Point3D Helix::getDerivative(double t) const
{
    return { -m_radius * std::sin(t), m_radius * std::cos(t), m_step };
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
