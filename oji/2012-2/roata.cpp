#include <fstream>
using namespace std;

int cabina[361];

int main()
{
	ifstream fin ("roata.in");
	ofstream fout ("roata.out");

	int n, p, nr_rotiri[100];
	fin >> n >> p;

	for (int i = 1; i <= p; i++)
		fin >> nr_rotiri[i];

	for (int i = 1; i > 0; i++)
	{	
		if (cabina[i] == 0)
		{
			int next_client = 1;
			while (nr_rotiri[next_client] == 0 && next_client != p)
				 next_client++;
			if (next_client == p && nr_rotiri[next_client] == 0)
				i = -1;

			cabina[i] = next_client;
			nr_rotiri[next_client]--;
		} else
			nr_rotiri[cabina[i]]--;

		if (nr_rotiri[cabina[i]] == 0)
			fout << "out: " << cabina[i] << "\n";

		if (i == n)
			i = 0;
	}

	fin.close();
	fout.close();

	return 0;
}