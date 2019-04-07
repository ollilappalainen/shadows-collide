#include "pch.h"
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Collision.h"
#include "AABBTest.h"

using namespace std;

double AABBTest::getMaxX(vector<Vector> polygon)
{
	double maxX = polygon.at(0).x;
	Vector last = polygon.at(0);

	for (Vector i : polygon)
	{
		if (i.x > last.x)
		{
			maxX = i.x;
		}

		last = i;
	}

	return maxX;
}

double AABBTest::getMinX(vector<Vector> polygon)
{
	double minX = polygon.at(0).x;
	Vector last = polygon.at(0);

	for (Vector i : polygon)
	{
		if (i.x < last.x)
		{
			minX = i.x;
		}

		last = i;
	}

	return minX;
}

double AABBTest::getMaxY(vector<Vector> polygon)
{
	double maxY = polygon.at(0).y;
	Vector last = polygon.at(0);

	for (Vector i : polygon)
	{
		if (i.y > last.y)
		{
			maxY = i.y;
		}

		last = i;
	}

	return maxY;
}

double AABBTest::getMinY(vector<Vector> polygon)
{
	double minY = polygon.at(0).y;
	Vector last = polygon.at(0);

	for (Vector i : polygon)
	{
		if (i.y < last.y)
		{
			minY = i.y;
		}

		last = i;
	}

	return minY;
}

double AABBTest::calculateDistance(Vector point1, Vector point2)
{
	return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2) * 1.0);
}

double AABBTest::getClosestPointsDistance(vector<Vector> polygon1, vector<Vector> polygon2)
{
	double shortestDistance = calculateDistance(polygon1.at(0), polygon2.at(0));
	double lastDistance = shortestDistance;

	for (Vector i : polygon1)
	{
		for (Vector t : polygon2)
		{
			double distance = calculateDistance(i, t);

			if (distance < shortestDistance)
			{
				shortestDistance = distance;
			}

			lastDistance = distance;
		}
	}

	return shortestDistance;
}

Collision AABBTest::testAABBCollision(vector<Vector> polygon1, vector<Vector> polygon2)
{
	Collision result;
	result.collision = false;
	result.distance = NULL;

	double polygon1MaxX = getMaxX(polygon1);
	double polygon1MaxY = getMaxY(polygon1);	
	double polygon1MinX = getMinX(polygon1);
	double polygon1MinY = getMinY(polygon1);
	double polygon2MaxX = getMaxX(polygon2);
	double polygon2MaxY = getMaxY(polygon2);
	double polygon2MinX = getMinX(polygon2);
	double polygon2MinY = getMinY(polygon2);

	if (
		polygon1MinX < polygon2MaxX &&
		polygon1MaxX > polygon2MinX &&
		polygon1MinY < polygon2MaxY &&
		polygon1MaxY > polygon2MinY
		)
	{
		result.collision = true;
	}

	result.distance = getClosestPointsDistance(polygon1, polygon2);

	return result;
}
