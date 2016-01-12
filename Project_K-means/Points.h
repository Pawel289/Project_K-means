#ifndef _POINTS_H
#define _POINTS_H

#include "Point.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
class Points
{
	std::vector<Point> Data; //wektor z danymi
public:

	Points(const std::string & file, const int & size);
	std::vector<Point> get_Points(){ return Data; }

	~Points(){};
};

#endif