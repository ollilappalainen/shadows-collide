#pragma once
#include "pch.h"
#include "Vector.h"
#include <iostream>
#include <vector>

class Circle
{
private:
	vector<Vector> _polygon;
	Vector _center;
	double _radius;
	Vector calculateCenter();
	double calculateRadius();
	void setCenter(Vector);
	void setRadius(double);
	void setPolygon(vector<Vector>);

public:
	Circle(vector<Vector> polygon);
	Vector center();
	double radius();
	static bool isCircle(vector<Vector>);
};