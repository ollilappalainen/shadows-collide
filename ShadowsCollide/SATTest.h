#pragma once
#include "pch.h"
#include "Vector.h"
#include "Collision.h"
#include "ConvexPolygon.h"
#include "Projection.h"
#include <iostream>
#include <vector>

class SATTest
{
private:
	static Projection getProjectionsOfPolygon(Vector, ConvexPolygon);
public:	
	static Collision testSATCollision(ConvexPolygon, ConvexPolygon);
};
