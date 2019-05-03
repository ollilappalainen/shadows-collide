#include "pch.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include "Vector.h"
#include "VectorValidation.h"
#include "ConvexPolygon.h"

using namespace std;

bool VectorValidation::validateString(string vectorString)
{
	bool isValid = false;

	for (char& c : vectorString) {

		bool isDigit = isdigit(c);

		if (isDigit || c == ' ' || c == ',' || c == '.' || c == '-')
		{
			isValid = true;
		}
		else
		{
			isValid = false;

			cout << "Please enter vectors in a valid format." << endl;

			break;
		}		
	}

	return isValid;
}

bool VectorValidation::validateVectors(vector<Vector> vectors)
{
	return validateLength(vectors) && validateConvexity(vectors);
}

bool VectorValidation::validateLength(vector<Vector> vectors)
{
	if (vectors.size() < 3) {
		cout << "Please enter at least 3 valid vectors." << endl;

		return false;
	}

	return true;
}

bool VectorValidation::validateConvexity(vector<Vector> vectors)
{
	if (!ConvexPolygon::isConvex(vectors))
	{
		cout << "Please enter a valid convex polygon." << endl;

		return false;
	}

	return true;
}