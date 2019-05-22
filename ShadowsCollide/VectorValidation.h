#pragma once
#include "pch.h"
#include <vector>
#include "Vector.h"

class VectorValidation
{
private:
	static bool validateLength(vector<Vector>);
	static bool validateConvexity(vector<Vector>);
public:
	static bool validateString(string);
	static bool validateVectors(vector<Vector>);	
};