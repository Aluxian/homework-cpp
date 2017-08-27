#include <fstream>
using namespace std;

int main()
{
	// Vars
	int *v = new int[11];

	// Get files
	ifstream fin ("sort-insertie.in");
	ofstream fout ("sort-insertie.out");

	int n = 10;
	int k = 1;

	fin >> v[1];

	// Get values from file and sort
	for (int i = 2; i <= n; i++)
	{
		int x; fin >> x;

		if (x > v[k])
			v[++k] = x;
		else
		{
			int j = k;

			while (v[j] > x && j > 0)
			{
				v[j+1] = v[j];
				j--;
			}

			v[j+1] = x; k++;
		}
	}

	// Write values
	for (int i = 1; i <= 10; i++)
		fout << v[i] << "\n";

	// Close files
	fin.close();
	fout.close();

	return 0;
}