#include <iostream>
#include "Program.h"
#include <cstdlib>
#include <sstream>

using namespace std;
int main(int argc, char *argv[])
{
	int size_of_point;
	int number_of_groups;
	istringstream s1(argv[1]);
	istringstream s2(argv[2]);
	s1 >> size_of_point;
	s2 >> number_of_groups;
	

	Program nowy;
	nowy.Grouping(size_of_point,number_of_groups);
	
	getchar();
	return 0;
}