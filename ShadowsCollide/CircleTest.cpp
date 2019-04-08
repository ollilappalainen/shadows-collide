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
	collision.distance = separatingLine.length;
	collision.collision = circle1.radius() + circle2.radius() < separatingLine.length;

	return collision;
}