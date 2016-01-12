#ifndef _RANDOM_GROUP_H
#define _RANDOM_GROUP_H
#include "Group.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <cmath>
class Random_Group
{
	std::vector<Point> Centers_of_Groups;
public:
	Random_Group(const int & number,std::vector<Point> & vector_Points);		//konstruktor
	std::vector<float> maximal_point(std::vector<Point> & vector_Points);			//wyznacza nowy punkt maksymalny w zbiorze	(funkcja pomocnicza do wyznaczania losowych œrodków grup)

	std::vector<Point> Get_Centers_of_Groups(){ return Centers_of_Groups; }

	~Random_Group(){};
};

#endif