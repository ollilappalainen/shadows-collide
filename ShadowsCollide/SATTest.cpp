#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Line.h"
#include "Collision.h"
#include "ConvexPolygon.h"
#include "ArithmeticalOperations.h"
#include "SATTest.h"

using namespace std;

Collision SATTest::testSATCollision(ConvexPolygon polygon1, ConvexPolygon polygon2)
{
	Collision collision;
	collision.collision = false;
	collision.distance = 0;

	return collision;
}