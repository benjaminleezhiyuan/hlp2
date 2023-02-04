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
#define PI 3.141592
#include <iostream> // istream, ostream

namespace hlp2
{
	class Point
	{
	public:
		// declare constructors (3)
		Point() {}
		Point(double arr[]) : x(arr[0]), y(arr[1]){};
		Point(double x, double y) : x(x), y(y){};

		// declare overloaded operators (8 member functions)

		// return coordinates from index
		double &operator[](int index);
		const double &operator[](int index) const;

		// translation
		Point &operator+=(const Point &other);
		Point &operator+=(double scal);

		// Incr
		Point &operator++();
		Point operator++(int);

		// Decr
		Point &operator--();
		Point operator--(int);

	private:
		double x; // The x-coordinate of a Point
		double y; // The y-coordinate of a Point
	};

	// declare 15 non-member, non-friend functions
	Point operator%(const Point &p, double degrees);
	double operator/(const Point &p1, const Point &p2);
	Point operator+(const Point &p1, const Point &p2);
	Point operator+(const Point &p, double scalar);
	Point operator+(double d, const Point &p);
	Point operator-(const Point &p1, const Point &p2);
	Point operator-(const Point &p, double d);
	Point operator-(double d, const Point &p);
	Point operator-(const Point &p);
	Point operator^(const Point &p1, const Point &p2);
	double operator*(const Point &p1, const Point &p2);
	Point operator*(const Point &p, double scale);
	Point operator*(double scale, const Point &p);
	std::ostream &operator<<(std::ostream &os, const Point &p);
	std::istream &operator>>(std::istream &is, Point &p);

} // end namespace hlp2

#endif // end POINT_HPP
////////////////////////////////////////////////////////////////////////////////
