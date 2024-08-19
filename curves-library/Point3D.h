#ifndef CADEX_CURVES_LIBRARY_POINT3D_H_
#define CADEX_CURVES_LIBRARY_POINT3D_H_

namespace cadex
{
class Point3D
{
public:
    Point3D() = default;
    Point3D(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

private:
    double m_x;
    double m_y;
    double m_z;
};
}

#endif
