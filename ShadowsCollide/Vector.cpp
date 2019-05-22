#include "Vector.h"
#include <math.h>

using namespace std;

double Vector::magnitude()
{
	return sqrt(x * x + y * y);
}