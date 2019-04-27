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
#include "ConvexPolygon.h"
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

bool isConvexPolygon(const vector<Vector> vectors)
{
	// todo
	bool isConvex = false;

	vector<double> slopes;
	for (int i = 0; i < vectors.size(); i++)
	{
		int maxIndex = vectors.size() - 1;		
		int first = i;
		int last = first == 0 ? maxIndex : first - 1;
		int second = first == maxIndex ? 0 : first + 1;

		//double slope1 = ArithmeticalOperations::calculateSlope(vectors.at(last), vectors.at(first));
		double slope2 = ArithmeticalOperations::calculateSlope(vectors.at(first), vectors.at(second));
		
		//slopes.push_back(slope1);
		slopes.push_back(slope2);

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

	slopes;
	return isConvex;
}

bool isOBB(const vector<Vector> vectors)
{
	// todo
	bool isOBB = false;
	   
	return isOBB;
}

void validateVectors(string vectors)
{
	// todo
}

int main()
{
	string vectorsString;
    cout << "Please enter a list of two or more X and Y vectors." << endl; 
	cout << "Vectors must form a convex polygon." << endl;
	cout << "Valid form: x,y x,y x,y ..." << endl;
	cout << "Example: -4.46,12.71 2.61,12.52 5.21,10.57 -3.46,8.71" << endl;
	cout << "Press CTRL + C to end program." << endl;
	cout << "Vectors: ";
	//getline(cin, vectorsString);

	//int vectorsCount = getArraySizeFromVectors(vectorsString);

	//-----
	//test start
	//	TEST CIRCLE COLLISION!!
	//-----
	string testString = "1.64,4.9 2.34,5.53 2.38,6.46 1.76,7.16 0.82,7.2 0.13,6.58 0.08,5.64 0.71,4.95";
	vector<Vector> testPolygon = Mutations::mutateVectorsStringToStdVector(testString);
	Circle testCircle(testPolygon);

	string secondTest = "6.13,1.64 6.75,2.53 6.74,3.62 6.08,4.49 5.04,4.81 4.01,4.46 3.39,3.57 3.4,2.48 4.06,1.61 5.1,1.29";
	vector<Vector> testPolygon2 = Mutations::mutateVectorsStringToStdVector(secondTest);
	Circle testCircle2(testPolygon2);

	Collision collision = CircleTest::testCircleCollision(testCircle, testCircle2);

	//-----
	// CONVEX POLYGON TEST
	//-----
	string convexPolyString = "11.56,7.57 10.97,11.86 7.97,12.68 6.69,7.64";
	vector<Vector> convexPolygon = Mutations::mutateVectorsStringToStdVector(convexPolyString);
	bool isConvex = ConvexPolygon::testConvexity(convexPolygon);
	//-----
	//test end
	//-----
	int vectorsCount = 3;
	if (vectorsCount > 1) {
		const vector<Vector> polygon1 = Mutations::mutateVectorsStringToStdVector(vectorsString);

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
