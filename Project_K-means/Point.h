#ifndef _POINT_H
#define _POINT_H

#include <iostream>
#include <vector>

class Point
{

	std::vector<float> one_point;
public:
	Point(){};
	Point(std::vector<float> some_point, int size);


	std::vector<float> get_point();
	~Point(){};
};

#endif