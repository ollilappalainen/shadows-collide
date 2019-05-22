#pragma once
#include "pch.h"
#include "Vector.h"
#include "Collision.h"
#include <iostream>
#include <vector>

class AABBTest
{
private:
	static double getMaxX(std::vector<Vector>);
	static double getMaxY(std::vector<Vector>);
	static double getMinX(std::vector<Vector>);
	static double getMinY(std::vector<Vector>);
	static double calculateDistance(Vector, Vector);
	static double getClosestPointsDistance(std::vector<Vector>, std::vector<Vector>);

public:
	static Collision testAABBCollision(std::vector<Vector>, std::vector<Vector>);
};