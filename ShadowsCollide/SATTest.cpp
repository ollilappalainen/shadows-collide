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

	vector<Vector> vectors = polygon1.getVectors();
	unsigned int vectorsCount = vectors.size();

	for (size_t i = 0; i < vectorsCount; i++)
	{
		unsigned int next = i + 1;

		if (i == vectorsCount - 1)
		{
			next = 0;
		}

		Line line(vectors.at(i), vectors.at(next));
		double slope = line.slope();
		double slopeN = -(1 / slope);
	}

	return collision;
}