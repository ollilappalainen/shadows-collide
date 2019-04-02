// ShadowsCollide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct Point
{
	// todo: add move this to geometries directory and change vector to Points
	int x, y;
};

int getArraySizeFromVectors(const string vectorString)
{
	size_t arraySize = count(vectorString.begin(), vectorString.end(), ' ') + 1;

	return arraySize;
}

const vector<double> mutateStringToVector(const string vectorString)
{
	vector<double> vect;
	stringstream ss(vectorString);

	double i;

	while (ss >> i)
	{
		vect.push_back(i);

		if (ss.peek() == ',')
		{
			ss.ignore();
		}
	}

	return vect;
}

const vector<vector<double>> mutateVectorsStringToArray(const string vectorString)
{
	vector<vector<double>> vectors;
	stringstream ss(vectorString);
	string i;
	vector<string> vectorTemp;

	while (getline(ss, i, ' '))
	{
		vectors.push_back(mutateStringToVector(i));
	}

	return vectors;
}

bool isQuadrangle(const vector<vector<double>> vectors)
{
	bool isQuandrangle;

	if (vectors.size() < 4 || vectors.size() > 4) {
		isQuandrangle = false;
	}

	for (int i = 0; i < 4; i++)
	{
		double dx, dy, slope;
		int index1 = 0;
		int index2 = 1;

		dx = vectors.at(index2).at(0) - vectors.at(index1).at(0);
		dy = vectors.at(index2).at(1) - vectors.at(index1).at(1);
		slope = dy / dx;

		isQuandrangle = (vectors.at(index1).at(0) == vectors.at(index2).at(0) || vectors.at(index1).at(1) == vectors.at(index2).at(1)) && isinf(slope);
	}

	return isQuandrangle;
}

int main()
{
	// -2,-2 -2,3 3,3 3,-2
	string vectorsString;
    cout << "Please enter a list of X and Y vectors" << endl; 
	cout << "Valid form: x,y x,y x,y ..." << endl;
	cout << "Example: -4.46,12.71 2.61,12.52 5.21,10.57 -3.46,8.71" << endl;
	getline(cin, vectorsString);

	int vectorsCount = getArraySizeFromVectors(vectorsString);

	const vector<vector<double>> vectors = mutateVectorsStringToArray(vectorsString);

	if (isQuadrangle(vectors))
	{
		cout << "Polygon is quadrangle" << endl;
	}
	else
	{
		cout << "Please enter quadangle.." << endl;
	}

	while (cin.good()) {
		cin.get();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
