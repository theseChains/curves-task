#ifndef CADEX_CURVES_LIBRARY_HELIX_H_
#define CADEX_CURVES_LIBRARY_HELIX_H_

#include "Curve.h"

namespace cadex
{
class Helix : public Curve
{
public:
    Helix(double radius, double step);

    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;

    double getRadius() const;
    double getStep() const;

    void setRadius(double radius);
    void setStep(double step);

private:
    double m_radius;
    double m_step;
};
}

#endif
