// ShadowsCollide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Vector.h"
#include "AABBTest.h"
#include "Collision.h"
#include "ArithmeticalOperations.h"
#include "Mutations.h"
#include "Circle.h"
#include "CircleTest.h"
#include "PolygonVsCircleTest.h"
#include "ConvexPolygon.h"
#include "SATTest.h"
#include "VectorValidation.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

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
		double dist12 = ArithmeticalOperations::distanceOfPoints(vect1, vect2);
		double dist34 = ArithmeticalOperations::distanceOfPoints(vect3, vect4);
		double dist23 = ArithmeticalOperations::distanceOfPoints(vect2, vect3);
		double dist41 = ArithmeticalOperations::distanceOfPoints(vect4, vect1);

		if (dist12 == dist34 && dist23 == dist41) {
			// Check if slopes are 0
			double slope1, slope2, slope3, slope4;

			slope1 = ArithmeticalOperations::calculateSlope(vect1, vect2);
			slope2 = ArithmeticalOperations::calculateSlope(vect2, vect3);
			slope3 = ArithmeticalOperations::calculateSlope(vect3, vect4);
			slope4 = ArithmeticalOperations::calculateSlope(vect4, vect1);

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

int main()
{
	string vectorsString;
	vector<Vector> polygon1;
	cout << "Please enter a list of three or more X and Y vectors." << endl;
	cout << "Vectors must form a convex polygon." << endl;
	cout << "Valid form: x,y x,y x,y ..." << endl;
	cout << "Example: -4.46,12.71 2.61,12.52 5.21,10.57 -3.46,8.71" << endl;
	cout << "Press CTRL + C to end program." << endl;

	bool isValidString = false;
	bool isValidVector = false;
	bool isValid = false;

	while (!isValid)
	{
		while (!isValid) {
			cout << "Vectors: ";
			getline(cin, vectorsString);

			isValid = VectorValidation::validateString(vectorsString);
		}

		polygon1 = Mutations::mutateVectorsStringToStdVector(vectorsString);		
		isValid = VectorValidation::validateVectors(polygon1);
	}

	/*
	TODO: DETERMINE POLYGON TYPE
	*/



	if (isAABB(polygon1))
	{
		cout << "Polygon is quadrangle" << endl;
		cout << "Please enter another." << endl;
		cout << "Vectors: ";

		getline(cin, vectorsString);

		const vector<Vector> polygon2 = Mutations::mutateVectorsStringToStdVector(vectorsString);

		if (isAABB(polygon2))
		{
			Collision collisionResult = AABBTest::testAABBCollision(polygon1, polygon2);

			string collision = collisionResult.collision == true ? "TRUE" : "FALSE";

			cout << "Collision: " << collision << endl;
			cout << "Distance: " << collisionResult.distance << endl;
		}
	}
	else
	{
		cout << "Please enter quadangle.." << endl;
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

