#include "Group.h"

using namespace std;


Group::Group(const int & number_of_group, vector<vector<Point>> & vector_of_groups, vector<Point> & exist_centers_of_groups)		//zwraca wektor srodkow grup
{
	//vector<Point> new_groups;
	vector<float> new_center;				//nowy srodek grupy
	vector<float> tmp_point;
	//int numbers_of_group = vector_of_groups.size();		//ilosc grup
	int size;											//rozmiar grupy

	for (int i = 0; i < number_of_group; i++)			//po grupach	(i)
	{
		size = vector_of_groups[i].size();

		if (!vector_of_groups[i].empty())
		{

			new_center = center(vector_of_groups[i]);				//wyznaczanie nowego srodka grup
			Centers_of_Groups.push_back(Point(new_center, new_center.size()));		//dodanie nowego punktu
		}
		else
		{
			tmp_point = exist_centers_of_groups[i].get_point();
			Centers_of_Groups.push_back(Point(tmp_point, tmp_point.size()));

		}



	}
	//return new_groups;
}


vector<float> Group::center(vector<Point> vector_Points)//przyjmuje wektor punktów pjedyñczej grupy		
{
	vector<float> vector_end;
	vector<float> point;
	vector<float> point_tmp;
	float result, sum;
	point = vector_Points[0].get_point();
	int size = point.size();					//ilosc wymiarow punktu

	for (int i = 0; i < size; i++)		//poruszanie sie po punkcie
	{
		result = 0;
		sum = 0;
		for (int j = 0; j < vector_Points.size(); j++)		//poruszanie sie po wektorze punktow
		{
			point_tmp = vector_Points[j].get_point();		//pobranie punktu
			sum = sum + point_tmp[i];
		}
		result = sum / vector_Points.size();
		vector_end.push_back(result);
	}

	return vector_end;
}