/*!*****************************************************************************
\file    point.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 05
\date    03-02-23

\brief

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
     *
     * @param index
     * @return double&
     *********************************************************************/
    double &Point::operator[](int index)
    {
        return (index == 0 ? x : y);
    }

    /******************************************************************
     * @brief
     *
     * @param index
     * @return const double&
     *********************************************************************/
    const double &Point::operator[](int index) const
    {
        return (index == 0 ? x : y);
    }

    /******************************************************************
     * @brief
     *
     * @param other
     * @return Point&
     *********************************************************************/
    Point &Point::operator+=(const Point &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    /******************************************************************
     * @brief
     *
     * @param scal
     * @return Point&
     *********************************************************************/
    Point &Point::operator+=(double scal)
    {
        x += scal;
        y += scal;
        return *this;
    }

    /******************************************************************
     * @brief
     *
     * @return Point&
     *********************************************************************/
    Point &Point::operator++()
    {
        ++x;
        ++y;
        return *this;
    }

    /******************************************************************
     * @brief
     *
     * @return Point
     *********************************************************************/
    Point Point::operator++(int)
    {
        Point temp(*this);
        ++(*this);
        return temp;
    }

    /******************************************************************
     * @brief
     *
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
     *
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
     *
     * @param p
     * @param degrees
     * @return Point
     *********************************************************************/
    Point operator%(const Point &p, double degrees)
    {
        double radian = degrees * PI / 180;
        double x = p[0] * cos(radian) - p[1] * sin(radian);
        double y = p[0] * sin(radian) - p[1] * cos(radian);
        return Point(x, y);
    }

    /******************************************************************
     * @brief
     *
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
     *
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
     *
     * @param p
     * @return Point
     *********************************************************************/
    Point operator-(const Point &p)
    {
        return Point(-p[0], -p[1]);
    }

} // end hlp2 namespace

///////////////////////////////////////////////////////////////////////////////
// define private stuff here [if any] in this anonymous namespace ...
namespace
{
}
