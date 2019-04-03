// ShadowsCollide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Vector.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int getArraySizeFromVectors(const string vectorString)
{
	size_t arraySize = count(vectorString.begin(), vectorString.end(), ' ') + 1;

	return arraySize;
}

const Vector mutateStringToVector(const string vectorString)
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

const vector<Vector> mutateVectorsStringToArray(const string vectorString)
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

double countDistance(Vector p, Vector q)
{
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

double countSlope(Vector v1, Vector v2)
{
	double dx, dy, slope;

	dx = v2.x - v1.x;
	dy = v2.y - v1.y;
	slope = dy / dx;

	return slope;
}

bool isAABB(const vector<Vector> vectors)
{
	bool isAABB;

	if (vectors.size() != 4) {
		isAABB = false;
	}
	else {
		Vector vect1 = vectors.at(0);
		Vector vect2 = vectors.at(1);
		Vector vect3 = vectors.at(2);
		Vector vect4 = vectors.at(3);

		// Check if opposite sides of quadrangle are same length
		double dist12 = countDistance(vect1, vect2);
		double dist34 = countDistance(vect3, vect4);
		double dist23 = countDistance(vect2, vect3);
		double dist41 = countDistance(vect4, vect1);

		if (dist12 == dist34 && dist23 == dist41) {
			// Check if slopes are 0
			double slope1, slope2, slope3, slope4;

			slope1 = countSlope(vect1, vect2);
			slope2 = countSlope(vect2, vect3);
			slope3 = countSlope(vect3, vect4);
			slope4 = countSlope(vect4, vect1);

			// If opposite slopes are same and all of them are 0
			isAABB = fabs(slope1) == fabs(slope3) && 
				fabs(slope2) == fabs(slope4) && 
				(isinf(slope1) || slope1 == 0) && 
				(isinf(slope2) || slope2 == 0) && 
				(isinf(slope3) || slope3 == 0) && 
				(isinf(slope4) || slope4 == 0);
		}
		else
		{
			isAABB = false;
		}
	}

	return isAABB;
}

bool isConvexPolygon(const vector<Vector> vectors)
{
	bool isConvex = false;

	for (int i = 0; i < vectors.size(); i++)
	{
		// figure this out..????
		/*int vectorsLastIndex = vectors.size() - 1;
		int middlePoint = i + 1;
		int endPoint1 = middlePoint - 1;
		int endPoint2 = middlePoint + 1;

		if (i == vectors.size())
		{
			middlePoint = 0;
			endPoint2 = 1;
		}
		else if (middlePoint == 0)
		{
			endPoint1 = vectorsLastIndex;
		}
		else if (middlePoint == vectorsLastIndex)
		{
			endPoint2 = 0;
		}

		Vector p1 = vectors.at(middlePoint);
		Vector p2 = vectors.at(endPoint1);
		Vector p3 = vectors.at(endPoint2);

		float dx21 = p2.x - p1.x;
		float dx31 = p3.x - p1.x;
		float dy21 = p2.y - p1.y;
		float dy31 = p3.y - p1.y;
		float m12 = sqrt(dx21*dx21 + dy21 * dy21);
		float m13 = sqrt(dx31*dx31 + dy31 * dy31);
		float theta = acos((dx21*dx31 + dy21 * dy31) / (m12 * m13));*/
	}

	return isConvex;
}

bool isOBB(const vector<Vector> vectors)
{
	bool isOBB = false;
	   
	return isOBB;
}

void validateVectors(string vectors)
{

}

int main()
{
	// -2,-2 -2,3 3,3 3,-2
	string vectorsString;
    cout << "Please enter a list of two or more X and Y vectors." << endl; 
	cout << "Vectors must form a convex polygon." << endl;
	cout << "Valid form: x,y x,y x,y ..." << endl;
	cout << "Example: -4.46,12.71 2.61,12.52 5.21,10.57 -3.46,8.71" << endl;
	cout << "Press CTRL + C to end program." << endl;
	cout << "Vectors: ";
	getline(cin, vectorsString);

	int vectorsCount = getArraySizeFromVectors(vectorsString);

	if (vectorsCount > 1) {
		const vector<Vector> vectors = mutateVectorsStringToArray(vectorsString);

		isConvexPolygon(vectors);

		if (isAABB(vectors))
		{
			cout << "Polygon is quadrangle" << endl;
		}
		else
		{
			cout << "Please enter quadangle.." << endl;
			cout << "Vectors: ";
			getline(cin, vectorsString);
		}
	}
	else {
		cout << "Please enter more than one vector." << endl;
		cout << "Vectors: ";
		getline(cin, vectorsString);
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
