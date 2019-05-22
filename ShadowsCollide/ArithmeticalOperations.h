#pragma once
#include "Vector.h"
#include <iostream>

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
