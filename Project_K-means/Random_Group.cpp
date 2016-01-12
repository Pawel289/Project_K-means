#include "Random_Group.h"

using namespace std;


Random_Group::Random_Group(const int & number,vector<Point> & vector_Points)
{
	// number-ilosc grup
	// max_point - wartosci maksymalne 
	//vector<Point> Groups;	//wektor zawieraj¹cy œrodki losowe grup
	vector<float> max_point = maximal_point(vector_Points);
	int size = max_point.size();		//wymiarowoœæ punktu
	vector<float> vector_tmp;					//wektor pomocniczy
	int max_tmp;						//zmienna wykorzystywana do rand
	srand(time(NULL));

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < size; j++)
		{

			int max_tmp = static_cast<int>(max_point[j]);
			vector_tmp.push_back(rand() % max_tmp);		//losowy punkt

		}
		Centers_of_Groups.push_back(Point(vector_tmp, size));
		vector_tmp.clear();
	}
	//return Groups;




}

vector<float> Random_Group::maximal_point(vector<Point> & vector_Points)			//wyznacza nowy punkt maksymalny w zbiorze	(funkcja pomocnicza do wyznaczania losowych œrodków grup)
{

	vector<float> vector_tmp;
	vector<float> point;		//wektor floatow
	vector<float> vector_end;

	point = vector_Points[0].get_point();		// n punktow
	int size = point.size();
	float tmp;
	for (int i = 0; i < size; i++)	//poruszanie siê po punkcie
	{
		tmp = point[i];
		for (int j = 1; j < vector_Points.size(); j++)	//poruszanie siê po wektorze punktów
		{
			vector_tmp = vector_Points[j].get_point();
			if (vector_tmp[i]>tmp)
			{
				tmp = vector_tmp[i];
			}

		}
		vector_end.push_back(tmp);
	}
	return vector_end;
}