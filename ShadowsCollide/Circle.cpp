#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Circle.h"
#include "Line.h"
#include "ArithmeticalOperations.h"

using namespace std;

Circle::Circle(vector<Vector> polygon)
{
	setPolygon(polygon);

	Vector center = calculateCenter();
	setCenter(center);

	double radius = calculateRadius();
	setRadius(radius);
}

void Circle::setPolygon(vector<Vector> polygon)
{
	_polygon = polygon;
}

void Circle::setCenter(Vector center)
{
	_center = center;
}

void Circle::setRadius(double radius)
{
	_radius = radius;
}

Vector Circle::center()
{
	return _center;
}

double Circle::radius()
{
	return _radius;
}

Vector Circle::calculateCenter()
{
	Vector center;
	Vector p1 = _polygon.at(0);
	Vector p2 = _polygon.at(1);
	Vector p3 = _polygon.at(2);
	Line l1(p1, p2);
	Line l2(p3, p2);
	double l1Slope = l1.slope();
	double l2Slope = l2.slope();
	center.x = (l1Slope * l2Slope * (p1.y - p3.y) + l2Slope * (p1.x + p2.x) - l1Slope * (p2.x + p3.x)) / (2 * (l2Slope - l1Slope));
	center.y = -1 * (center.x - (p1.x + p2.x) / 2) / l1Slope + (p1.y + p2.y) / 2;

	return center;
}

double Circle::calculateRadius()
{	
	return ArithmeticalOperations::distanceOfPoints(_center, _polygon.at(0));
}

