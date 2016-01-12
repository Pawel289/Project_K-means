#include "Program.h"



using namespace std;


bool Program::end_of_program(vector<Point> &group_1, vector<Point> &group_2)
{
	vector<float> vector_tmp_1;
	vector<float> vector_tmp_2;


	for (int i = 0; i < group_1.size(); i++)
	{
		vector_tmp_1 = group_1[i].get_point();
		vector_tmp_2 = group_2[i].get_point();
		for (int j = 0; j < vector_tmp_1.size(); j++)
		{
			if (vector_tmp_1[j] != vector_tmp_2[j])
			{
				return false;
			}
		}
	}

	return true;
}


float Program::distance_points(Point & PointA, Point & PointB)
{
	float result, diff, pow, sum;
	vector<float> point_tmp_A, point_tmp_B;
	point_tmp_A = PointA.get_point();				//pierwszy punkt
	point_tmp_B = PointB.get_point();				//drugi punkt
	int size = point_tmp_A.size();					//liczba wymiarow pojedynczego punktu
	sum = 0;
	for (int i = 0; i < size; i++)
	{
		diff = point_tmp_A[i] - point_tmp_B[i];		//odejmowanie
		pow = diff*diff;							//potegowanie
		sum = sum + pow;							//sumowanie
	}

	return result = sqrt(sum);						//pierwiastek z sumy

}


void Program::save_file(vector<vector<Point>> & vector_of_groups,const string & file, const int & dimension)
{
	fstream myfile;
	myfile.open(file, ios::out);
	if (!myfile.good())
	{
		cout << "blad";
	}
	int numbers_of_group = vector_of_groups.size();	//ilosc grup
	int size;										//rozmiar grupy
	vector<float> point_tmp;

	for (int i = 0; i < numbers_of_group; i++)
	{
		myfile << "Grupa " << i << endl;
		size = vector_of_groups[i].size();
		for (int j = 0; j < size; j++)
		{
			point_tmp = vector_of_groups[i][j].get_point();
			for (int k = 0; k < dimension; k++)
			{
				myfile << point_tmp[k] << " ";

			}
			myfile << endl;

		}

	}

	myfile.close();
}

vector<vector<Point>> Program::assign_to_group(vector<Point> & vector_Points, vector<Point> & centers_of_groups)
{
	int numbers_of_groups = centers_of_groups.size();	//liczba grup
	int numbers_of_points = vector_Points.size();
	vector<vector<Point>> vector_groups(numbers_of_groups);
	vector<Point> vector_tmp;				//wektor pomocniczy
	float min, tmp;	//min - zmienna przechowujaca wartosc minimalna, tmp - zmienna pomocnicza
	int index;
	for (int i = 0; i < numbers_of_points; i++)
	{
		for (int j = 0; j < numbers_of_groups; j++)
		{
			if (j == 0)
			{
				min = tmp = distance_points(vector_Points[i], centers_of_groups[j]);		//porównanie pierwszego srodka grup z danym punktem
				index = j;
			}
			else
			{
				tmp = distance_points(vector_Points[i], centers_of_groups[j]);			//porownywanie kolejnych œrodków grup z danym punktem
			}

			if (tmp < min)				//porównanie dotychczasowej odleg³oœci minimalnej z obliczon¹
			{
				min = tmp;				//ustawienie nowej wartoœci minimalnej
				index = j;				//ustawienie indeksu grupy le¿¹cej bli¿ej badanego punktu
			}


		}
		vector_tmp = vector_groups[index];		//zapisanie aktualnej wartosci wektora grup do wektora pomocniczego
		vector_tmp.push_back(vector_Points[i]);
		vector_groups[index] = vector_tmp;
		vector_tmp.clear();
	}

	return vector_groups;
}


void Program::Grouping(const int & size_of_point, const int &numbers_of_groups)
{
	std::vector<std::vector<Point>> Groups;
	std::vector<Point> old_centers, present_centers;


	Points dane("dane.txt", size_of_point);		//objekt z danymi z pliku
	Random_Group rand_centers(numbers_of_groups, dane.get_Points());		//utworzenie losowych œrodków grup
	old_centers = rand_centers.Get_Centers_of_Groups();	//stare œrodki
	Groups = assign_to_group(dane.get_Points(), rand_centers.Get_Centers_of_Groups());  //pierwsze grupy (ca³e z punktami)
	Group new_centers(numbers_of_groups, Groups, rand_centers.Get_Centers_of_Groups());		//nowe srodki
	present_centers = new_centers.Get_Centers_of_Groups();
	Groups = assign_to_group(dane.get_Points(), new_centers.Get_Centers_of_Groups());	//nowe grupy(ca³e z punktami)

	int i = 0;
	while (!end_of_program(old_centers, present_centers))
	{
		i++;
		old_centers = present_centers;
		Group new_centers(numbers_of_groups, Groups, present_centers);		//nowe srodki
		present_centers = new_centers.Get_Centers_of_Groups();
		Groups = assign_to_group(dane.get_Points(), present_centers);

	}
	save_file(Groups, "wynik.txt", size_of_point);

}