#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Collision.h"
#include "AABBTest.h"
#include "Circle.h"
#include "Line.h"
#include "CircleTest.h"

using namespace std;

Collision CircleTest::testCircleCollision(Circle circle1, Circle circle2)
{
	Collision collision;
	Line separatingLine(circle1.center(), circle2.center());
	double radiusTotal = circle1.radius() + circle2.radius();
	collision.collision = radiusTotal > separatingLine.length();
	collision.distance = collision.collision ? 0 : separatingLine.length() - radiusTotal;

	return collision;
}