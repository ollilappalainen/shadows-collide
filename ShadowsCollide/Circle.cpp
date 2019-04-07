#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Circle.h"

using namespace std;

Circle::Circle(vector<Vector> polygon)
{
	setCenter(calculateCenter(polygon));
}

void Circle::setCenter(Vector center)
{
	_center = center;
}

Vector Circle::center()
{
	return _center;
}

Vector Circle::calculateCenter(vector<Vector> polygon)
{
	Vector center;

	return center;
}

