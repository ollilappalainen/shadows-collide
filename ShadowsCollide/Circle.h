#pragma once
#include "pch.h"
#include "Vector.h"
#include <iostream>
#include <vector>

using namespace std;

class Circle
{
private:
	vector<Vector> _polygon;
	Vector _center;
	Vector calculateCenter(vector<Vector> polygon);
	void setCenter(Vector);

public:
	Circle(vector<Vector> polygon);
	Vector center();
};