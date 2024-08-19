#ifndef CADEX_CURVES_LIBRARY_CURVE_H_
#define CADEX_CURVES_LIBRARY_CURVE_H_

#include "Point3D.h"

namespace cadex
{
class Curve
{
public:
    virtual Point3D getPoint(double t) const = 0;
    virtual Point3D getDerivative(double t) const = 0;

    virtual ~Curve() = default;
};
}

#endif
