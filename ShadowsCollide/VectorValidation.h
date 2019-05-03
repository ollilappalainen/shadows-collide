#pragma once
#include "pch.h"
#include <vector>
#include "Vector.h"

using namespace std;

class VectorValidation
{
private:
	static bool validateLength(vector<Vector>);
	static bool validateConvexity(vector<Vector>);
public:
	static bool validateString(string);
	static bool validateVectors(vector<Vector>);	
};