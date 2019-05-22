#include <iostream>
#include <vector>
#include "Vector.h"
#include "Line.h"
#include "ArithmeticalOperations.h"

using namespace std;

Line::Line(Vector p1, Vector p2)
{
	double slope = ArithmeticalOperations::calculateSlope(p1, p2);
	double length = ArithmeticalOperations::distanceOfPoints(p1, p2);
	Vector center = calculateCenter(p1, p2);
	setSlope(slope);
	setLength(length);
	setCenter(center);
	setPoints(p1, p2);
}

void Line::setPoints(Vector p1, Vector p2)
{
	_p1 = p1;
	_p2 = p2;
}

void Line::setSlope(double slope)
{
	_slope = slope;
}

void Line::setCenter(Vector center)
{
	_center = center;
}

void Line::setLength(double length)
{
	_length = length;
}

double Line::slope()
{
	return _slope;
}

double Line::length()
{
	return _length;
}

Vector Line::center()
{
	return _center;
}

Vector Line::xy()
{
	return _p1;
}

Vector Line::calculateCenter(Vector p1, Vector p2)
{
	double xDifference = p1.x - p2.x;
	double yDifference = p1.y - p2.y;

	Vector center;
	center.x = xDifference / 2;
	center.y = yDifference / 2;

	return center;
}
