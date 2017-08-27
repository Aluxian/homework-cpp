#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	ifstream fin ("mcript.in");
	ofstream fout ("mcript.out");

	int N;
	fin >> N;

	long sirRaw;
	fin >> sirRaw;

	int digits = 0, sir[11];

	for (int s = sirRaw; s > 0; digits++)
		s /= 10;

	for (int i = 1; i <= digits; i++)
		sir[(int) (sirRaw / pow(10, digits - i)) % 10] = i;

	int cuvinteDicNo;
	fin >> cuvinteDicNo;
	int dictionar[cuvinteDicNo+1];

	for (int i = 1; i <= cuvinteDicNo; i++)
		fin >> dictionar[i];

	int K;
	fin >> K;
	int propozitie[K+1][10000];

	for (int i = 1; i <= K; i++)
	{
		fin >> propozitie[i][0];

		for (int j = 1; j <= propozitie[i][0]; j++)
			fin >> propozitie[i][j];
	}

	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= propozitie[i][0]; j++)
		{
			int word = propozitie[i][j];

			while (word > 0)
			{
				
			}
		}
	}

	fin.close();
	fout.close();

	return 0;
}