#pragma once
#include "pch.h"
#include "Vector.h"
#include "Collision.h"
#include "ConvexPolygon.h"
#include "Circle.h"
#include "Projection.h"
#include <iostream>
#include <vector>

using namespace std;

class PolygonVsCircleTest
{
public:
	static Collision testCollision(ConvexPolygon, Circle);
};
