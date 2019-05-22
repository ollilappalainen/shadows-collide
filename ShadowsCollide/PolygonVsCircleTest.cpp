#include <iostream>
#include <vector>
#include "Vector.h"
#include "Projection.h"
#include "Line.h"
#include "Collision.h"
#include "ConvexPolygon.h"
#include "Circle.h"
#include "ArithmeticalOperations.h"
#include "Mutations.h"
#include "PolygonVsCircleTest.h"

using namespace std;

Collision PolygonVsCircleTest::testCollision(ConvexPolygon polygon, Circle circle)
{
	Collision collision;
	collision.collision = false;
	collision.distance = NULL;

	vector<Vector> vectors = polygon.getVectors();

	for (size_t i = 0; i < vectors.size(); i++)
	{

		
		// TODO
		// Does not properly determine distance or collision
		Vector vector = vectors.at(i);
		double fromPointToCenter = ArithmeticalOperations::distanceOfPoints(vector, circle.center());
		double distance = fromPointToCenter - circle.radius();

		if (collision.distance == NULL || collision.distance > distance)
		{
			collision.distance = distance;
		}		

		if (collision.distance <= 0)
		{
			collision.collision = true;
		}
	}

	return collision;
}