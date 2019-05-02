#include "pch.h"
#include "Vector.h"
#include "Line.h"
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

double ArithmeticalOperations::getCrossProduct(Vector lineStart, Vector lineEnd, Vector point)
{
	Vector v1, v2;

	v1.x = lineEnd.x - lineStart.x;
	v1.y = lineEnd.y - lineStart.y;
	v2.x = lineEnd.x - point.x;
	v2.y = lineEnd.y - point.y;

	return v1.x * v2.y - v1.y * v2.x;
}

Vector ArithmeticalOperations::getProjectionOfPoint(Vector lineP1, Vector lineP2, Vector pointToProject)
{
	Line line(lineP1, lineP2);
	double slope = line.slope();
	double eq = lineP1.y - (slope * lineP1.x);
	Vector projection;

	projection.x = (slope * pointToProject.y + pointToProject.x - slope * eq) / (slope * slope + 1);
	projection.y = (slope * slope * pointToProject.y + slope * pointToProject.x + eq) / (slope * slope + 1);

	return projection;
}