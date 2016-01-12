#include "Points.h"

using namespace std;

Points::Points(const string & file,const int & size)
{
	vector<float> point_tmp;
	//vector<Point>Points;
	fstream myfile;
	int liczba_danych = size;
	float data;
	myfile.open(file);
	if (!myfile.good())
	{
		cout << "blad otwarcia pliku!!";
	}
	else
	{
		while (!myfile.eof())
		{
			for (int i = 0; i < liczba_danych; i++)
			{
				myfile >> data;
				point_tmp.push_back(data);		//jeden punkt (linia z pliku)
			}

			Data.push_back(Point(point_tmp, size));
			point_tmp.clear();

		}


		myfile.close();
		
	}




}