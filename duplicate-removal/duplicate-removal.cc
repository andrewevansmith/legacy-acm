/*
	Title:			Duplicate Removal	
	Author: Legacy archive
	Description:	Example for ACM	
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	ifstream input_file("dup.txt");
	ofstream output_file("out.txt");
	char current, previous; 
	if ((!input_file) || (!output_file))
	{
		cout << "Failure opening files.\n";
		return -1;
	}
	input_file >> previous;
	while (input_file >> current)		
	{
		if (!(current == previous))	
			cout << current << " ";
		previous = current;		
	}
	cout << "$\n";
	return 0;
}

// End of driver file
