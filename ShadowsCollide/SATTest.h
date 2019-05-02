#pragma once
#include "pch.h"
#include "Vector.h"
#include "Collision.h"
#include "ConvexPolygon.h"
#include <iostream>
#include <vector>

using namespace std;

class SATTest
{
private:
	static vector<Vector> getProjectionsOfPolygon(Vector, Vector, ConvexPolygon);
	static bool separatingAxisTest(ConvexPolygon, ConvexPolygon);
public:	
	static Collision testSATCollision(ConvexPolygon, ConvexPolygon);
};
