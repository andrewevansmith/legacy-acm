// A-Z Roman Numerals


#include <iostream>
#include <cmath> 
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int digits(int n) 
{
	string s;
	stringstream out;
	out << n;
	return out.str().size();
}


int main()
{
	cout.setf (ios::fixed, ios::basefield);
	int count = 0;
	cout.precision(20);

	char lowercase[] = {'a','b','c','d','e','f','g','h','i','j','k',
			  'l','m','n','o','p','q','r'};

	char uppercase[] = {'A','B','C','D','E','F','G','H','I','J','K',
		     'L','M','N','O','P','Q','R'};

	long double nupper[18], nlower[18];	

	for (int i=0; i<18; i++)
	{
		nupper[i] = 5*(pow(10, i));
		nlower[i] = pow(10, i);
	}

	char input[64];
	string out = "";

	while (true)
	{
		string out = "";
		cout << "N: ";
		cin >> input;

		int length = strlen(input)-1;
		unsigned long int n = atoi(input);
		bool lower, upper;

		count = 0;
		while (n != 0)
		{
			if ((n>0) && (n<nupper[length]-nlower[length]))
			{
				out.append(1,lowercase[length]);
				n -= nlower[length];
			}

			else if ((n>=nupper[length]-nlower[length]) && (n<nupper[length]))
			{
				out.append(1,lowercase[length]);
				n += nlower[length];
			}

			else if ((n>=nupper[length]) && (n<nlower[length+1]-nlower[length]))
			{
				out.append(1,uppercase[length]);
				n -= nupper[length];
			}

			else if ((n>=nlower[length]-nlower[length]) && (n<nlower[length+1]))
			{
				out.append(1,lowercase[length]);
				n += nlower[length];
			}
			length = digits(n) - 1;
		}	
		cout << endl << out << endl;
	}
	return 0;
}
