#pragma once
#include "pch.h"
#include "Vector.h"
#include "Collision.h"
#include <iostream>
#include <vector>

class AABBTest
{
private:
	static double getMaxX(vector<Vector> polygon);
	static double getMaxY(vector<Vector> polygon);
	static double getMinX(vector<Vector> polygon);
	static double getMinY(vector<Vector> polygon);
	static double calculateDistance(Vector, Vector);
	static double getClosestPointsDistance(vector<Vector> polygon1, vector<Vector> polygon2);

public:
	static Collision testAABBCollision(vector<Vector> polygon1, vector<Vector> polygon2);
};