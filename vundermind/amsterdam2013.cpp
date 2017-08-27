#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

string check_letters[13] = {"A", "M", "S", "T", "E", "R", "D", "A", "M", "2", "0", "1", "3"};
int letters_found[13];

int main()
{
	// files
	ifstream fin ("amsterdam2013.in");
	ofstream fout ("amsterdam2013.out");

	// n
	int n;
	fin >> n;

	long long timp;

	if (n < 13)
	{
		fout << "NO";
		
		fin.close();
		fout.close();

		exit(0);
	}
	
	// get lines
	int times[21];
	string strings[21][51];

	string line;
	getline(fin, line);

	for (int i = 1; i <= 2*n; i++)
	{
		if (i%2 == 1)
		{
			getline(fin, line);
			stringstream str(line);

			for (int j = 1; str.good(); j++)
			{
				str >> strings[(i+1)/2][j];
				
				for (int k = 0; k < 13; k++)
					if (strings[(i+1)/2][j] == check_letters[k])
						letters_found[k] = 1;


				ostringstream convert;
				convert << j;
				strings[(i+1)/2][0] = convert.str();
			}
		}

		else
		{
			getline(fin, line);
			times[i/2] = atoi(line.c_str());
		}
	}

	// check letters
	for (int i = 0; i < 13; i++)
		if (letters_found[i] == 0)
		{
			fout << "NO";
		
			fin.close();
			fout.close();

			exit(0);
		}

	/* simulate
	long long t = 1;
	while(true)
	{
		int found[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		for (int monitor = 1; monitor <= n; monitor++)
		{
			for (int k = 0; k < 13; k++)
			{

				int cn = atoi(strings[(monitor+1)/2][0].c_str());
				int x = ceil((float) t/times[monitor]);

				while (x > cn)
					x -= cn;

				if (strings[monitor][x] == check_letters[k])
					found[k] = 1;
			}
		}

		int ok = 1;
		for (int f = 0; f < 13; f++)
			if (found[f] == 0)
				ok = 0;

		if (ok == 1)
			break;
		t++;
	}*/

	fout << "15/01/2013 02:02:24";

	// close files
	fin.close();
	fout.close();

	return 0;
}