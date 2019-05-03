#pragma once
#include "pch.h"
#include "Vector.h"
#include "Line.h"
#include <iostream>
#include <vector>

using namespace std;

class ConvexPolygon
{
private:
	vector<Vector> _polygon;
	vector<Line> _edges;
	void setPolygon(vector<Vector>);
	void setEdges(vector<Vector>);
public:
	static bool isConvex(vector<Vector> polygon);
	vector<Line> getEdges();
	vector<Vector> getVectors();
	ConvexPolygon(vector<Vector> polygon);
};
