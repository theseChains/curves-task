#ifndef CADEX_CURVES_LIBRARY_CIRCLE_H_
#define CADEX_CURVES_LIBRARY_CIRCLE_H_

#include "Curve.h"

namespace cadex
{
class Circle : public Curve
{
public:
    Circle(double radius);

    Point3D getPoint(double t) const override;

    double getRadius() const;
    void setRadius(double radius);

private:
    double m_radius;
};
}

#endif
