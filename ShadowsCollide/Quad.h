#pragma once
#include "pch.h"
#include <vector>
#include "Vector.h"
#include "Line.h"

class Quad
{
private:
	std::vector<Vector> _polygon;
	std::vector<Line> _edges;
	void setPolygon(std::vector<Vector>);
	void setEdges(std::vector<Vector>);
public:
	static bool isAABB(std::vector<Vector>);
	std::vector<Vector> getVectors();
	std::vector<Line> getEdges();
	Quad(std::vector<Vector>);
};