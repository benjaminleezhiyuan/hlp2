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
    double &Point::operator[](int index)
    {
        return (index == 0 ? x : y);
    }
    const double &Point::operator[](int index) const
    {
        return (index == 0 ? x : y);
    }

    // define 15 non-member, non-friend functions

} // end hlp2 namespace

///////////////////////////////////////////////////////////////////////////////
// define private stuff here [if any] in this anonymous namespace ...
namespace
{
}
