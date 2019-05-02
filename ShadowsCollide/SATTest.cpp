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

vector<Vector> SATTest::getProjectionsOfPolygon(Vector lineP1, Vector lineP2, ConvexPolygon polygon)
{
	vector<Vector> vectors = polygon.getVectors();
	unsigned int vectorsCount = vectors.size();
	vector<Vector> projections;

	for (size_t a = 0; a < vectorsCount; a++)
	{
		Vector pointToProject = vectors.at(a);
		Vector projection = ArithmeticalOperations::getProjectionOfPoint(lineP1, lineP2, pointToProject);
		projections.push_back(projection);
	}

	return projections;
}

bool SATTest::separatingAxisTest(ConvexPolygon polygon1, ConvexPolygon polygon2)
{
	vector<Vector> vectors = polygon1.getVectors();
	unsigned int vectorsCount = vectors.size();	
	bool hasSeparatingAxis = true;

	for (size_t i = 0; i < vectorsCount; i++)
	{
		unsigned int next = i + 1;

		if (i == vectorsCount - 1)
		{
			next = 0;
		}

		Vector lineP1, lineP2;
		vector<Vector> projections1, projections2;

		lineP1 = vectors.at(i);
		lineP2 = vectors.at(next);

		projections1 = getProjectionsOfPolygon(lineP1, lineP2, polygon1);
		projections2 = getProjectionsOfPolygon(lineP1, lineP2, polygon2);

		for (size_t a = 0; a < vectors.size(); a++)
		{
			double projection = vectors.at(a).dotProduct(lineP1);
			// TODO
		}

		if (!hasSeparatingAxis) {
			break;
		}
	}

	return hasSeparatingAxis;
}

Collision SATTest::testSATCollision(ConvexPolygon polygon1, ConvexPolygon polygon2)
{
	Collision collision;
	collision.collision = false;
	collision.distance = -DBL_MAX;

	bool test1 = separatingAxisTest(polygon1, polygon2);
	bool test2 = separatingAxisTest(polygon2, polygon1);

	collision.collision = !test1 && !test2;

	return collision;
}
