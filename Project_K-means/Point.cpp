#include "Point.h"

using namespace std;

Point::Point(vector<float> some_point, int size)
{
	some_point.resize(size);
	for (int i = 0; i < size; i++)
	{
		one_point.push_back(some_point[i]);
	}
}

vector<float> Point::get_point()
{
	return one_point;
}