#pragma once
#include "pch.h"
#include "Vector.h"
#include <iostream>
#include <vector>

using namespace std;

class Line
{
private:
	Vector _p1;
	Vector _p2;
	Vector _center;	
	double _slope;
	double _length;
	void setPoints(Vector, Vector);
	void setSlope(double);
	void setCenter(Vector);
	void setLength(double);
	Vector calculateCenter(Vector, Vector);
public:
	Line(Vector p1, Vector p2);
	double slope();
	Vector center();
	double length();
	Vector xy();
};
