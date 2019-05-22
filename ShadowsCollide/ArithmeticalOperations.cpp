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

double ArithmeticalOperations::getDotProduct(Vector axis, Vector toProject)
{
	return axis.x * toProject.x  + axis.y * toProject.y;
}

Vector ArithmeticalOperations::calculateCenterOfCircle(Vector p1, Vector p2, Vector p3)
{
	Vector center;
	Line l1(p1, p2);
	Line l2(p3, p2);
	double l1Slope = l1.slope();
	double l2Slope = l2.slope();
	center.x = (l1Slope * l2Slope * (p1.y - p3.y) + l2Slope * (p1.x + p2.x) - l1Slope * (p2.x + p3.x)) / (2 * (l2Slope - l1Slope));
	center.y = -1 * (center.x - (p1.x + p2.x) / 2) / l1Slope + (p1.y + p2.y) / 2;

	return center;
}
