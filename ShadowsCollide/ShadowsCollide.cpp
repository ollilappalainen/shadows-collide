#include "Vector.h"
#include "AABBTest.h"
#include "Collision.h"
#include "Mutations.h"
#include "Circle.h"
#include "CircleTest.h"
#include "PolygonVsCircleTest.h"
#include "ConvexPolygon.h"
#include "SATTest.h"
#include "Quad.h"
#include "VectorValidation.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <signal.h>
#include <windows.h>

using namespace std;

Collision testCollision(vector<Vector> polygon1, vector<Vector> polygon2)
{
	Collision collision;
	collision.collision = false;
	collision.distance = NULL;

	// Determine collision test type
	if (Quad::isAABB(polygon1) && Quad::isAABB(polygon2))
	{
		cout << "Operating AABB vs AABB collision test.." << endl;
		collision = AABBTest::testAABBCollision(polygon1, polygon2);
	}
	else if (Circle::isCircle(polygon1) && Circle::isCircle(polygon2))
	{
		cout << "Operating Circle vs Circle collision test.." << endl;
		collision = CircleTest::testCircleCollision(polygon1, polygon2);
	}
	else {
		cout << "Operating Separating Axis test for arbitrary convex polygons.." << endl;
		collision = SATTest::testSATCollision(polygon1, polygon2);
	}

	return collision;
}

/*
TEST FUNCTIONS
*/
Collision aabbTest() {
	string aabbstring1 = "3,3 3,6 5,6 5,3";
	string aabbstring2 = "6,3 6,6 9,6 9,3";
	vector<Vector> aabbpol1 = Mutations::mutateVectorsStringToStdVector(aabbstring1);
	vector<Vector> aabbpol2 = Mutations::mutateVectorsStringToStdVector(aabbstring2);

	return AABBTest::testAABBCollision(aabbpol1, aabbpol2);
}
/*
TEST FUNCTIONS END
*/

int main()
{
	/*
	TESTS START
	*/
	Collision aabbTestCollision = aabbTest();


	/*
	TESTS END
	*/

	string vectorsString;
	vector<Vector> polygon1;
	vector<Vector> polygon2;
	cout << "Please enter a list of three or more X and Y vectors." << endl << endl;
	cout << "Vectors must form a convex polygon." << endl;
	cout << "Valid form: x,y x,y x,y ..." << endl;
	cout << "Example: -4.46,12.71 2.61,12.52 5.21,10.57 -3.46,8.71" << endl;
	cout << "Press CTRL + C to end program." << endl << endl;

	bool isValidString = false;
	bool isValidVector = false;
	bool isValid = false;

	//Get first set of vectors
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

	isValid = false;

	cout << endl;
	cout << "Enter another list of three or more X and Y vectors." << endl;

	//Get second set of vectors
	while (!isValid)
	{
		while (!isValid) {
			cout << "Vectors: ";
			getline(cin, vectorsString);

			isValid = VectorValidation::validateString(vectorsString);
		}

		polygon2 = Mutations::mutateVectorsStringToStdVector(vectorsString);
		isValid = VectorValidation::validateVectors(polygon2);
	}

	cout << endl;

	Collision collision = testCollision(polygon1, polygon2);

	string didItBump = collision.collision ? "TRUE" : "FALSE";

	cout << endl;
	cout << "RESULT" << endl;
	cout << "######" << endl;
	cout << endl;
	cout << "COLLISION: " << didItBump << endl;
	cout << "DISTANCE: " << collision.distance << endl;
	cout << endl;
	cout << "Press CTRL + C to end program." << endl;

	while (cin.good()) {
		cin.get();
	}
}
