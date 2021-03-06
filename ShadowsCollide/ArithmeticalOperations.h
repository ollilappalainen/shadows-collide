#pragma once
#include "pch.h"
#include "Vector.h"
#include <iostream>

using namespace std;

class ArithmeticalOperations
{
public:
	static double calculateSlope(Vector, Vector);
	static double distanceOfPoints(Vector, Vector);
	static double getCrossProduct(Vector lineStart, Vector lineEnd, Vector point);
	static Vector getProjectionOfPoint(Vector, Vector, Vector);
	static double getDotProduct(Vector, Vector);
	static Vector calculateCenterOfCircle(Vector, Vector, Vector);
};
