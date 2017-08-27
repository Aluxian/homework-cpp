#include <iostream>
using namespace std;

int v[1000];

int main()
{
	int m, n; cin >> m >> n;

	for (int i = 0; i < n; ++i)
	{
		int f = 2, n;
		cin >> n;

		while (n != 1)
		{
			int p = 0;

			while (n%f == 0)
			{
				n /= f;
				p++;
			}

			if (p != 0)
				v[f] = p;

			f++;
		}
	}

	for (int i = 0; i < 100; ++i)
		if (v[i] != 0)
			cout << i << '^' << v[i] << endl;

	cin >> n;
	return 0;
}