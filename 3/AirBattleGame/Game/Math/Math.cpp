#include "Math.hpp"

Vector x(1, 0);
Vector y(0, 1);
namespace MATH {
    double deg2Rad(double angle) { return (angle * Pi) / 180; }

    double distanceTo(Point& _point1, Point& _point2)
    {
        return  sqrt((_point2.x - _point1.x) * (_point2.x - _point1.x)
            +
            (_point2.y - _point1.y) * (_point2.y - _point1.y));
    }

    double angleBetweenVectors(Vector& v1, Vector& v2)
    {
        double ch = (v1.a * v2.a + v1.b * v2.b);
        double l1 = sqrt((double)v1.a * v1.a + (double)v1.b * v1.b);
        double l2 = sqrt((double)v2.a * v2.a + (double)v2.b * v2.b);
        double del = l1 * l2;
        double t = ch / del;
        if (t < -1) t = -1;
        else if (t > 1) t = 1;
        return (acos(t) * 180) / 3.14;
    }
    bool isBetween(Vector& a, Vector& b, Vector& check) {
        double angle = MATH::angleBetweenVectors(a, b);
        double p = angle - MATH::angleBetweenVectors(x, check);
        double angle2 = MATH::angleBetweenVectors(x, check);
        double angle3 = MATH::angleBetweenVectors(check, b);
        if (angle >= angle2 && (int)p == (int)angle3) // Need to add close comparison
        {
            return true;
        }
        return false;
    }
    /*!
        \todo Try cos(arccos(alpha))
    */
    double normalisation(double ang)
    {
        double angle;
        if (ang < 0) {
            if (ang < -360) {
                int k = (-1) * ang / 360;
                ang += (360 * k);
            }
            angle = 360 + ang;
            return angle;
        }
        else if (ang > 360)
        {
            int k = ang / 360;
            ang -= (k * 360);
            return ang;
        }
        else angle = ang;
        return angle;
    }

    std::pair<Vector, Vector>& getViewVectors(double angle, double Radius, Vector& rad, double attackAngle)// Searching 2 view vectors
    {
        double half = (double)attackAngle / 2;
        double newAngle1 = normalisation(((angle + half) * 3.14) / 180);
        double newAngle2 = normalisation(((angle - half) * 3.14) / 180);
        Vector vec1(Radius * cos((newAngle1 * 3.14) / 180), Radius * sin((newAngle1 * 3.14) / 180));
        Vector vec2(Radius * cos((newAngle2 * 3.14) / 180), Radius * sin((newAngle2 * 3.14) / 180));
        std::pair<Vector, Vector> vectors = std::make_pair(vec1, vec2);
        return vectors;
    }
}
