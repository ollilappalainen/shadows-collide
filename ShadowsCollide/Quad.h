#pragma once
#include "pch.h"
#include <vector>
#include "Vector.h"
#include "Line.h"

using namespace std;

class Quad
{
private:
	vector<Vector> _polygon;
	vector<Line> _edges;
	void setPolygon(vector<Vector>);
	void setEdges(vector<Vector>);
public:
	static bool isAABB(vector<Vector>);
	vector<Vector> getVectors();
	vector<Line> getEdges();
	Quad(vector<Vector>);
};