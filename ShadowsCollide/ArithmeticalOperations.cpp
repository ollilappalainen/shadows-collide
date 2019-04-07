#include "pch.h"
#include "Vector.h"
#include "ArithmeticalOperations.h"
#include <iostream>

using namespace std;

double ArithmeticalOperations::calculateSlope(Vector p1, Vector p2)
{
	double dx, dy, slope;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	slope = dy / dx;

	return slope;
}

double ArithmeticalOperations::distanceOfPoints(Vector p1, Vector p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) * 1.0);
}