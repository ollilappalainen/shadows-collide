#include "pch.h"
#include <vector>
#include "Vector.h"
#include "Quad.h"
#include "ArithmeticalOperations.h"

Quad::Quad(vector<Vector> polygon)
{
	setPolygon(polygon);
	setEdges(polygon);
}

void Quad::setPolygon(vector<Vector> polygon)
{
	_polygon = polygon;
}

vector<Vector> Quad::getVectors()
{
	return _polygon;
}

bool Quad::isAABB(vector<Vector> polygon)
{
	bool isAABB;

	if (polygon.size() != 4) {
		isAABB = false;
	}
	else {
		Vector vect1 = polygon.at(0);
		Vector vect2 = polygon.at(1);
		Vector vect3 = polygon.at(2);
		Vector vect4 = polygon.at(3);

		// Check if opposite sides of quadrangle are same length
		double dist12 = ArithmeticalOperations::distanceOfPoints(vect1, vect2);
		double dist34 = ArithmeticalOperations::distanceOfPoints(vect3, vect4);
		double dist23 = ArithmeticalOperations::distanceOfPoints(vect2, vect3);
		double dist41 = ArithmeticalOperations::distanceOfPoints(vect4, vect1);

		if (dist12 == dist34 && dist23 == dist41) {
			// Check if slopes are 0
			double slope1, slope2, slope3, slope4;

			slope1 = ArithmeticalOperations::calculateSlope(vect1, vect2);
			slope2 = ArithmeticalOperations::calculateSlope(vect2, vect3);
			slope3 = ArithmeticalOperations::calculateSlope(vect3, vect4);
			slope4 = ArithmeticalOperations::calculateSlope(vect4, vect1);

			// If opposite slopes are inf or 0
			if ((fabs(slope1) == 0 || isinf(slope1)) && (fabs(slope2) == 0 || isinf(slope2)) && (fabs(slope3) == 0 || isinf(slope3)) && (fabs(slope4) == 0 || isinf(slope4)))
			{
				isAABB = true;
			}
			else
			{
				isAABB = false;
			}
		}
		else
		{
			isAABB = false;
		}
	}

	return isAABB;
}

void Quad::setEdges(vector<Vector> polygon)
{
	vector<Line> edges;

	for (size_t i = 0; i < polygon.size(); i++)
	{
		size_t next = i + 1;

		if (i == polygon.size() - 1)
		{
			next = 0;
		}

		Vector p1 = polygon.at(i);
		Vector p2 = polygon.at(next);
		Line edge(p1, p2);

		edges.push_back(edge);
	}

	_edges = edges;
}

vector<Line> Quad::getEdges()
{
	return _edges;
}
