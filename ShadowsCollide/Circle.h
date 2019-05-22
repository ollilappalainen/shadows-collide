#pragma once
#include "Vector.h"
#include <iostream>
#include <vector>

class Circle
{
private:
	std::vector<Vector> _polygon;
	Vector _center;
	double _radius;
	Vector calculateCenter();
	double calculateRadius();
	void setCenter(Vector);
	void setRadius(double);
	void setPolygon(std::vector<Vector>);

public:
	Circle(std::vector<Vector> polygon);
	Vector center();
	double radius();
	static bool isCircle(std::vector<Vector>);
};