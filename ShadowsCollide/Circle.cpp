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
	Vector p1 = _polygon.at(0);
	Vector p2 = _polygon.at(1);
	Vector p3 = _polygon.at(2);
	Vector center = ArithmeticalOperations::calculateCenterOfCircle(p1, p2, p3);

	return center;
}

double Circle::calculateRadius()
{	
	return ArithmeticalOperations::distanceOfPoints(_center, _polygon.at(0));
}

bool Circle::isCircle(vector<Vector> polygon)
{
	size_t vectorCount = polygon.size();

	if (vectorCount < 8)
	{
		return false;
	}

	Vector center = ArithmeticalOperations::calculateCenterOfCircle(polygon.at(0), polygon.at(1), polygon.at(2));
	double lastRadius = ArithmeticalOperations::distanceOfPoints(center, polygon.at(0));

	// Round the initial value for last radius to 0.1
	lastRadius = (int)(lastRadius * 10 + .5);
	lastRadius = (double)lastRadius / 10;

	bool isCircle = false;

	for (size_t i = 0; i < vectorCount; i++)
	{		
		Vector p1 = polygon.at(i);

		double radius = ArithmeticalOperations::distanceOfPoints(center, p1);

		// Round radius width to 0.1 decimals
		radius = (int)(radius * 10 + .5);
		radius = (double)radius / 10;

		// Check mach with previous radious with 0.1 decimal threshold
		if (radius == lastRadius || (radius + 0.1) == lastRadius || (radius - 0.1) == lastRadius)
		{
			isCircle = true;
		} 
		else {
			isCircle = false;
			break;
		}

		lastRadius = radius;
	}

	return isCircle;
}