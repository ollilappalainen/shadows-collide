#include "pch.h"
#include "Vector.h"

double Vector::dotProduct(Vector vector)
{
	return x * vector.x + y * vector.y;
}