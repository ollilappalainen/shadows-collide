#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Line.h"
#include "ConvexPolygon.h"
#include "ArithmeticalOperations.h"

using namespace std;

void ConvexPolygon::setPolygon(vector<Vector> polygon)
{
	_polygon = polygon;
}

bool ConvexPolygon::isConvex(vector<Vector> polygon)
{
	bool isConvex = false;

	for (size_t i = 0; i < polygon.size(); i++)
	{
		// Form line iteratively from every pair of vectors in polygon
		int next = i + 1;

		if (i == polygon.size() - 1) 
		{
			next = 0;
		}

		Vector p1 = polygon.at(i);
		Vector p2 = polygon.at(next);
		Line side(p1, p2);

		// Check if all points are at the same side of line with crossproduct of line and a point
		vector<double> crossProducts;

		for (size_t a = 0; a < polygon.size(); a++)
		{
			Vector p = polygon.at(a);
			double crossProd = ArithmeticalOperations::getCrossProduct(p1, p2, p);

			crossProducts.push_back(crossProd);		
		}		

		// Count amount of smaller, bigger and equal with 0 crossproducts
		int countOfSmaller = 0;
		int countOfBigger = 0;
		int countOfEqual = 0;
		
		for (auto& prod : crossProducts)
		{
			if (prod > 0)
			{
				countOfBigger++;
			} 
			else if (prod < 0)
			{
				countOfSmaller++;
			}
			else if (prod == 0)
			{
				countOfEqual++;
			}
		}

		// If smaller and equal sum or bigger and equal sum are the size of all the points
		// We can expect that all the points are on the same side of line
		int smallerYValues = countOfSmaller + countOfEqual;
		int biggerYValues = countOfBigger + countOfEqual;

		if (smallerYValues == crossProducts.size() || biggerYValues == crossProducts.size())
		{
			isConvex = true;
		}
		else {
			isConvex = false;
			break;
		}
	}

	return isConvex;
}

void ConvexPolygon::setEdges(vector<Vector> polygon)
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

vector<Vector> ConvexPolygon::getVectors()
{
	return _polygon;
}

vector<Line> ConvexPolygon::getEdges()
{
	return _edges;
}

ConvexPolygon::ConvexPolygon(vector<Vector> polygon)
{
	setPolygon(polygon);
	setEdges(polygon);
}
