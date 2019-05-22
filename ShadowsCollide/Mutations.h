#pragma once
#include "pch.h"
#include "Vector.h"
#include <vector>
#include <iostream>

class Mutations
{
public:
	static Vector mutateStringToVector(std::string);
	static std::vector<Vector> mutateVectorsStringToStdVector(std::string vectorString);
	static Vector getNormalizedVector(Vector);
};
