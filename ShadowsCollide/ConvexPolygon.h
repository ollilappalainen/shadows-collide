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
	void setPolygon(vector<Vector>);
public:
	static bool isConvex(vector<Vector> polygon);
	vector<Vector> getVectors();
	ConvexPolygon(vector<Vector> polygon);
};