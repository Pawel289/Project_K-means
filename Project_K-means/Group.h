#ifndef _GROUP_H
#define _GROUP_H

#include <iostream>
#include <vector>
#include "Point.h"

class Group
{
	std::vector<Point> Centers_of_Groups;
public:

	Group(const int & number_of_group, std::vector<std::vector<Point>> & vector_of_groups, std::vector<Point> & exist_centers_of_groups);
	std::vector<float> center(std::vector<Point> vector_Points);		//zwraca nowy srodek grupy (funkcja pomocnicza)

	std::vector<Point> Get_Centers_of_Groups(){ return Centers_of_Groups; }
	~Group(){};
};


#endif