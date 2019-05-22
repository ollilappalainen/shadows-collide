#pragma once
#include <vector>
#include "Vector.h"

class VectorValidation
{
private:
	static bool validateLength(std::vector<Vector>);
	static bool validateConvexity(std::vector<Vector>);
public:
	static bool validateString(std::string);
	static bool validateVectors(std::vector<Vector>);
};