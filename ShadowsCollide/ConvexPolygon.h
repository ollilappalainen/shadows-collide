#pragma once
#include "pch.h"
#include "Vector.h"
#include "Line.h"
#include <iostream>
#include <vector>

class ConvexPolygon
{
private:
	std::vector<Vector> _polygon;
	std::vector<Line> _edges;
	void setPolygon(std::vector<Vector>);
	void setEdges(std::vector<Vector>);
public:
	static bool isConvex(std::vector<Vector> polygon);
	std::vector<Line> getEdges();
	std::vector<Vector> getVectors();
	ConvexPolygon(std::vector<Vector> polygon);
};
