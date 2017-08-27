#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("elicop.in");
	ofstream fout ("elicop.out");

	int m, n, k, gazon[100][100], coord[100][6];
	fin >> m >> n;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			fin >> gazon[i][j];

	fin >> k;

	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= 5; j++)
			fin >> coord[i][j];

	for (int i = 1; i <= k; i++)
	{
		if (coord[i][5] > 0)
		{
			int length = coord[i][2] - coord[i][4];

			for (int l = coord[i][1]; l <= coord[i][3]; l++)
			{
				for (int j = coord[i][4]; j <= coord[i][4] + length; j++)
					fout << gazon[l][j] << "\n";

				length--;
			}
		}

		else
		{

		}
	}

	fin.close();
	fout.close();

	return 0;
}