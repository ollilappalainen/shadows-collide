#include "Vector.h"
#include "Mutations.h"
#include <iostream>
#include <sstream>

using namespace std;

Vector Mutations::mutateStringToVector(string vectorString)
{
	Vector vect;
	vect.x = NULL;
	vect.y = NULL;

	stringstream ss(vectorString);

	double i;

	while (ss >> i)
	{
		vect.x == NULL ? vect.x = i : vect.y = i;

		if (ss.peek() == ',')
		{
			ss.ignore();
		}
	}

	return vect;
}

vector<Vector> Mutations::mutateVectorsStringToStdVector(string vectorString)
{
	vector<Vector> vectors;
	stringstream ss(vectorString);
	string i;
	vector<string> vectorTemp;

	while (getline(ss, i, ' '))
	{
		vectors.push_back(mutateStringToVector(i));
	}

	return vectors;
}

Vector Mutations::getNormalizedVector(Vector vector)
{
	double x = vector.x / vector.magnitude();
	double y = vector.y / vector.magnitude();

	Vector normalized;
	normalized.x = x;
	normalized.y = y;

	return normalized;
}
