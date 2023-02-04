/*!*****************************************************************************
\file    point.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 05
\date    03-02-23

\brief
This file contains definitions to all the function operators
**********************************************************************************/

// Since your clients will not have access to this file, your initial
// inclination will be to avoid documenting this file ...
// However, since you're a client too and will need to understand this
// file's contents at a later point in time, the documentation you provide
// now will make the process of maininting this code base easier and more
// efficient.
// Therefore, make sure to provide file-level documentation and some
// function-level documentation for each function that you'll implement to
// avoid unnecessary grade deductions.

#include "point.hpp" // Point interface
#include <cmath>     // sin, cos, sqrt

///////////////////////////////////////////////////////////////////////////////
// declare private stuff here [if any] in this anonymous namespace ...
namespace
{
}

///////////////////////////////////////////////////////////////////////////////

namespace hlp2
{
    // define 8 member functions
    /******************************************************************
     * @brief
     * get coordinates based on index
     * @param index
     * @return
     * coordinate of point
     *********************************************************************/
    double &Point::operator[](int index)
    {
        return (index == 0 ? x : y);
    }

    /******************************************************************
     * @brief
     * get coordinates based on index
     * @param index
     * @return
     * coordinate of point
     *********************************************************************/
    const double &Point::operator[](int index) const
    {
        return (index == 0 ? x : y);
    }

    /******************************************************************
     * @brief
     * overloads that add two Point s or Point and double
     * Same behavior as built-in types.
     * @param other
     * @return
     * Point object
     *********************************************************************/
    Point &Point::operator+=(const Point &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    /******************************************************************
     * @brief
     * overloads that add two Point s or Point and double
     * Same behavior as built-in types.
     * @param scal
     * @return
     * Point object
     *********************************************************************/
    Point &Point::operator+=(double scal)
    {
        x += scal;
        y += scal;
        return *this;
    }

    /******************************************************************
     * @brief
     * Increment Point 's coordinates. Same behavior as built-in types.
     * @return 
     * Point object
     *********************************************************************/
    Point &Point::operator++()
    {
        ++x;
        ++y;
        return *this;
    }

    /******************************************************************
     * @brief
     * Increment Point 's coordinates. Same behavior as built-in types.
     * @return 
     * Point object
     *********************************************************************/
    Point Point::operator++(int)
    {
        Point temp(*this);
        ++(*this);
        return temp;
    }

    /******************************************************************
     * @brief
     * Decrement Point 's coordinates. Same behavior as built-in types.
     * @return Point&
     *********************************************************************/
    Point &Point::operator--()
    {
        --x;
        --y;
        return *this;
    }

    /******************************************************************
     * @brief
     * Decrement Point 's coordinates. Same behavior as built-in types.
     *********************************************************************/
    Point Point::operator--(int)
    {
        Point temp(*this);
        --(*this);
        return temp;
    }
    // define 15 non-member, non-friend functions

    /******************************************************************
     * @brief
     * Return Point obtained by rotating Point by double degrees.
     * @param p
     * @param degrees
     * @return Point
     *********************************************************************/
    Point operator%(const Point &p, double degrees)
    {
        double radian = degrees * PI / 180;
        double x = p[0] * cos(radian) - p[1] * sin(radian);
        double y = p[0] * sin(radian) + p[1] * cos(radian);
        return Point(x, y);
    }

    /******************************************************************
     * @brief
     * Return distance between two Point s.
     * @param p1
     * @param p2
     * @return double
     *********************************************************************/
    double operator/(const Point &p1, const Point &p2)
    {
        double x = p2[0] - p1[0];
        double y = p2[1] - p1[1];
        return sqrt(x * x + y * y);
    }

    /******************************************************************
     * @brief
     * 6 functions returning Point obtained by
     * adding/subtracting two Point s or Point and double or
     * double and Point operands.

     * @param p1
     * @param p2
     * @return Point
     *********************************************************************/
    Point operator+(const Point &p1, const Point &p2)
    {
        return Point(p1[0] + p2[0], p1[1] + p2[1]);
    }

    Point operator+(const Point &p, double scalar)
    {
        return Point(p[0] + scalar, p[1] + scalar);
    }

    Point operator+(double d, const Point &p)
    {
        return Point(p[0] + d, p[1] + d);
    }

    Point operator-(const Point &p1, const Point &p2)
    {
        return Point(p1[0] - p2[0], p1[1] - p2[1]);
    }

    Point operator-(const Point &p, double scalar)
    {
        return Point(p[0] - scalar, p[1] - scalar);
    }

    Point operator-(double d, const Point &p)
    {
        return Point(d - p[0], d - p[1]);
    }

    /******************************************************************
     * @brief
     * Return Point obtained by negating operand's coordinates.
     * @param p
     * @return
     * Point coordinates.
     *********************************************************************/
    Point operator-(const Point &p)
    {
        return Point(-p[0], -p[1]);
    }

    /******************************************************************
     * @brief
     * Return Point midway between two Point s.
     * @param p1
     * @param p2
     * @return Point
     *********************************************************************/
    Point operator^(const Point &p1, const Point &p2)
    {
        return Point((p1[0] + p2[0]) / 2, (p1[1] + p2[1]) / 2);
    }

    /******************************************************************
     * @brief
     * Return double representing dot or scalar product of two Point operands.
     * @param p1
     * @param p2
     * @return double
     *********************************************************************/
    double operator*(const Point &p1, const Point &p2)
    {
        return p1[0] * p2[0] + p1[1] * p2[1];
    }

    /******************************************************************
     * @brief
     * 2 functions that return Point obtained by scaling Point and double operands.
     * @param p
     * @param scale
     * @return Point
     *********************************************************************/
    Point operator*(const Point &p, double scale)
    {
        return Point(p[0] * scale, p[1] * scale);
    }
    Point operator*(double scale, const Point &p)
    {
        return Point(p[0] * scale, p[1] * scale);
    }

    /******************************************************************
     * @brief
     * Writes to output stream coordinates of Point in format (x, y) .
     * @param os
     * @param p
     * @return std::ostream&
     *********************************************************************/
    std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << '(' << p[0] << ", " << p[1] << ')';
        return os;
    }

    /******************************************************************
     * @brief
     * Reads two double s as Point from input stream.
     * @param is
     * @param p
     * @return std::istream&
     *********************************************************************/
    std::istream &operator>>(std::istream &is, Point &p)
    {
        is >> p[0] >> p[1];
        return is;
    }
    // end hlp2 namespace

    ///////////////////////////////////////////////////////////////////////////////
    // define private stuff here [if any] in this anonymous namespace ...
    namespace
    {
    }
}
