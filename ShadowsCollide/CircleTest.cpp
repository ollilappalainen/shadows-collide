#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Collision.h"
#include "AABBTest.h"
#include "CircleTest.h"

using namespace std;

void CircleTest::setCenter(Vector center)
{
	_center = center;
}

Vector CircleTest::calculateCenter(vector<Vector> polygon1)
{

}

Vector CircleTest::getCenter()
{
	return _center;
}

Collision CircleTest::testCircleCollision(vector<Vector> polygon1, vector<Vector> polygon2)
{

}