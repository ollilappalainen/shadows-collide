#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Projection.h"
#include "Line.h"
#include "Collision.h"
#include "ConvexPolygon.h"
#include "ArithmeticalOperations.h"
#include "SATTest.h"
#include "Mutations.h"

using namespace std;

Collision SATTest::testSATCollision(ConvexPolygon polygon1, ConvexPolygon polygon2)
{
	Collision collision;
	collision.collision = true;
	collision.distance = -DBL_MAX;

	vector<Line> edges1 = polygon1.getEdges();
	vector<Line> edges2 = polygon2.getEdges();

	// Iterate through all edges of both polygons
	for (size_t i = 0; i < edges1.size() + edges2.size(); i++)
	{
		Line edge = edges1.at(0);

		if (i < edges1.size())
		{
			edge = edges1.at(i);
		}
		else
		{
			edge = edges2.at(i - edges1.size());
		}

		// Set normalized perpendicular axis
		Vector axis = edge.xy();
		Vector perp;
		perp.x = -axis.y;
		perp.y = axis.x;
		Vector normal =	Mutations::getNormalizedVector(perp);

		Projection projection1 = getProjectionsOfPolygon(normal, polygon1);
		Projection projection2 = getProjectionsOfPolygon(normal, polygon2);

		if (projection1.min < projection2.min)
		{
			collision.distance = projection2.min - projection1.max;
		}
		else {
			collision.distance = projection1.min - projection2.max;
		}

		if (projection1.max < projection2.min || projection1.min > projection2.max)
		{
			collision.collision = false;
			break;
		}
	}

	return collision;
}

Projection SATTest::getProjectionsOfPolygon(Vector axis, ConvexPolygon polygon)
{
	vector<Vector> vectors = polygon.getVectors();
	double dp = ArithmeticalOperations::getDotProduct(axis, vectors.at(0));
	double min = dp;
	double max = dp;

	for (size_t a = 0; a < vectors.size(); a++)
	{
		dp = ArithmeticalOperations::getDotProduct(axis, vectors.at(a));

		if (dp < min) {
			min = dp;
		}
		else if (dp > max) {
			max = dp;
		}
	}

	Projection projection;
	projection.min = min;
	projection.max = max;

	return projection;
}
