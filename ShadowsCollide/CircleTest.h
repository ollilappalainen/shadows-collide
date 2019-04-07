#pragma once
#include "pch.h"
#include "Vector.h"
#include "Collision.h"
#include <iostream>
#include <vector>

using namespace std;

class CircleTest
{
private:
	Vector _center;
	Vector calculateCenter(vector<Vector> polygon1);
	Vector getCenter();
	void setCenter(Vector);

public:
	static Collision testCircleCollision(vector<Vector> polygon1, vector<Vector> polygon2);
};