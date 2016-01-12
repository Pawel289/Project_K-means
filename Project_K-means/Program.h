#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <iostream>
#include "Point.h"
#include "Points.h"
#include "Random_Group.h"
#include "Group.h"
#include <vector>
class Program
{
	

public:
	
	Program(){};

	void Grouping(const int & size_of_point, const int & numbers_of_groups);

	bool end_of_program(std::vector<Point> &group_1, std::vector<Point> &group_2);	// zwraca true jesli grupy nie zmieniaja sie, oznacza koniec obliczeñ

	float distance_points(Point & PointA, Point & PointB);					//zwraca odleglosc miedzy punktami

	std::vector<std::vector<Point>> assign_to_group(std::vector<Point> & vector_Points, std::vector<Point> & centers_of_groups);	//zwraca wektor z podzia³em na grupy, pobiera wektor z wszystkimi punktami, wektor z srodkami grup

	void Program::save_file(std::vector<std::vector<Point>> & vector_of_groups, const std::string & file, const int & dimension);

	~Program(){};
};

#endif