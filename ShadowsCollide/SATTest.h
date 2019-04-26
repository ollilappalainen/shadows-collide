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
public:
	static Collision testSATCollision(ConvexPolygon, ConvexPolygon);
};
