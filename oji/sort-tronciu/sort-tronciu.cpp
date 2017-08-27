#include <fstream>
using namespace std;

int main()
{
	// Vars
	int *v = new int[100];

	// Get files
	ifstream fin ("sort-tronciu.in");
	ofstream fout ("sort-tronciu.out");

	// Get values from file
	for (int i = 1; i <= 100; i++)
		fin >> v[i];

	// Sort
	int pos = 1, no_elem = 100;
	v[0] = -1;

	while (pos < no_elem)
	{
		if (v[pos] > v[pos+1])
		{
			int aux = v[pos];
			v[pos] = v[pos+1];
			v[pos+1] = aux;
			pos--;
		}

		else
			pos++;
	}

	// Write values
	for (int i = 1; i <= 100; i++)
		fout << v[i] << "\n";

	// Close files
	fin.close();
	fout.close();

	return 0;
}