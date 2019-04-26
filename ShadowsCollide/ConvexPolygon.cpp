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

bool ConvexPolygon::testConvexity(vector<Vector> polygon)
{
	bool isConvex = false;

	for (int i = 0; i < polygon.size(); i++)
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

		// Check if all points are at the same side of line
		vector<double> vectorsYOnLine;

		for (int a = 0; a < polygon.size(); a++)
		{
			Vector p = polygon.at(a);
			double pointOnLine = side.slope() * p.x + p1.y;			

			vectorsYOnLine.push_back(pointOnLine);		
		}		

		//Count amount of smaller, bigger and equal Y axis values on line
		int countOfSmaller = 0;
		int countOfBigger = 0;
		int countOfEqual = 0;
		
		for (auto& yPos : vectorsYOnLine)
		{
			if (yPos > p1.y)
			{
				countOfBigger++;
			} 
			else if (yPos < p1.y)
			{
				countOfSmaller++;
			}
			else if (yPos == p1.y)
			{
				countOfEqual++;
			}
		}

		// If smalle and equal sum or bigger and equal sum are the size of all the points
		// We can expect that all the points are on the same side of line
		if (countOfSmaller + countOfEqual == vectorsYOnLine.size() ||
			countOfBigger + countOfEqual == vectorsYOnLine.size())
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

ConvexPolygon::ConvexPolygon(vector<Vector> polygon)
{
	setPolygon(polygon);
}
