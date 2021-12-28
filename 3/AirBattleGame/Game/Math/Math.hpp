#pragma once
/*! \file */
/////////////////
/// Headers
/////////////////
#include <iostream>
#include<cmath>

#define Pi 3.1415926535

///////////////////////////////
/// \brief Point structure
/// 
/// It helps in Vector analysing
/// 
////////////////////////////////
struct Point {
    double x;
    double y;
    Point(double _x, double _y) :x(_x), y(_y) {  };
    bool operator == (const Point& point)
    {
        if (point.x == x && point.y == y)return true;
        return false;
    }
};
/////////////////////////////////////////////////////
/// \brief Helper vector function
/// We use it when we want to find square of ovetview of planeship.
/// In the future i want to implement a game version with barricades 
/// so we need to have vectors
/// 
//////////////////////////////////////////////////////////////////
struct Vector {
    Vector(double a, double b) :a(a), b(b) {};
    Vector(double x1, double y1, double x2, double y2) :a(x2 - x1), b(y2 - y1) {};
    double a, b; // Ratio of a guiding vector
};
//! Mathematical namespace MATH
namespace MATH {
    // double Pi = 3.1415926535;

    /////////////////////////////////////////////
    /// \brief Translation from degree to radian
    /// 
    /// \param angle 
    /// 
    /// \return  radians from angle in double
    /// 
    /////////////////////////////////////////////
    double deg2Rad(double angle);
    /////////////////////////////////////////////////
    /// \brief Getting distance between two Points
    /// \param _point1 First point
    /// \param _point2 Second point
    /// \return distance in double
    /// 
    //////////////////////////////////////////////////
    double distanceTo(Point& _point1, Point& _point2);
   
    double angleBetweenVectors(Vector& v1, Vector& v2);
    /////////////////////////////////////////////////
    /// \brief Checking function to see: is check vector between a and b or not
    /// 
    /// \param a Vector A
    /// \param b Vecror B
    /// \param check Checkable Vector
    /// 
    /// \return bool. True if is between,if not - False
    /// 
    ///////////////////////////////////////////////////

    bool isBetween(Vector& a, Vector& b, Vector& check);
    ///////////////////////////////////
    /// \brief Bringing the angle to the range [0;360]
    ///
    ////////////////////////////////////////////////////

    double normalisation(double ang);
    //////////////////////////////////////////////////////
    /// \brief Getting vectors limiting the overview
    /// 
    /// This is help function to get overview square.
    /// \param angle Streight view angle
    /// \param Radius View radius
    /// \param attackAngle Common(left/ right) View angle
    /// 
    /// \return std::pair<Vector, Vector>& . Reference of pair of overview vectors 
    /// 
    /// \todo Delete rad
    /// 
    ///////////////////////////////////////////////

    std::pair<Vector, Vector>& getViewVectors(double angle, double Radius, Vector& rad, double attackAngle);// Searching 2 view vectors
} // namespace MATH
