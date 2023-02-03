/*!*****************************************************************************
\file    point.hpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 05
\date    03-02-23

\brief

**********************************************************************************/

// make sure to provide file-level documentation and function-level
// documentation for each function that you'll implement to avoid
// unnecessary grade deductions.

////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_HPP
#define POINT_HPP
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace hlp2 {
class Point {
public:
	// declare constructors (3)
	Point(); //default
	Point(int,int); //int int
	Point(double,double); //double double

	// declare overloaded operators (8 member functions)
	Point Point::operator[](int index);
	Point Point::operator+=()

private:
	double x; // The x-coordinate of a Point
	double y; // The y-coordinate of a Point
};
  
// declare 15 non-member, non-friend functions 

} // end namespace hlp2

#endif // end POINT_HPP
////////////////////////////////////////////////////////////////////////////////
