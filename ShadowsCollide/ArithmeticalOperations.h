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
};
