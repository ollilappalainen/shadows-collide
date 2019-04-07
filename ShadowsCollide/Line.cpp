#include "pch.h"
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
	setSlope(slope);
	setLength(length);
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


