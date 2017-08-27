#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;

void binary(int n) {
   cout << "binary : ";
        for (int i=31; i>=0; i--) {
            int bit = ((n >> i) & 1);
            cout << bit;
        }
        cout << endl;
}

int main()
{
	// files
	ifstream fin ("bikes.in");
	ofstream fout ("bikes.out");

	string no, str = ""; fin >> no;

	for (int i = 0; i < no.length(); i++)
	{
		if ((int) no.at(i) >= 48 && (int) no.at(i) <= 57)
			str += no.at(i);
		else
		{
			ostringstream convert;
			convert << ((int) no.at(i)) - 55;
			str += convert.str();
		}
	}

	binary(35);
	
	// close files
	fin.close();
	fout.close();

	return 0;
}