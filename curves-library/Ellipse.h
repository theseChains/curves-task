#ifndef CADEX_CURVES_LIBRARY_CIRCLE_H_
#define CADEX_CURVES_LIBRARY_CIRCLE_H_

#include "Curve.h"

namespace cadex
{
class Ellipse : public Curve
{
public:
    Ellipse(double xRadius, double yRadius);

    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;

    double getXRadius() const;
    double getYRadius() const;

    void setXRadius(double xRadius);
    void setYRadius(double yRadius);

private:
    double m_xRadius;
    double m_yRadius;
};
}

#endif
