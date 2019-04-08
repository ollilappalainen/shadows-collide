#pragma once
#include "pch.h"
#include "Vector.h"
#include "Collision.h"
#include <iostream>
#include <vector>

using namespace std;

class CircleTest
{
public:
	static Collision testCircleCollision(vector<Vector> polygon1, vector<Vector> polygon2);
};