#pragma once
#include "pch.h"
#include "Vector.h"
#include <vector>
#include <iostream>

using namespace std;

class Mutations
{
public:
	static Vector mutateStringToVector(string);
	static vector<Vector> mutateVectorsStringToStdVector(string vectorString);
	static Vector getNormalizedVector(Vector);
};
