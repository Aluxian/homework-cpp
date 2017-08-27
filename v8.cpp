#include <iostream>
using namespace std;

int main()
{
	int n, nr = 0;
	cin >> n;
	int v[n+1];

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	for (int i = 1; i <= n-nr; i++)
	{
		int og = 0, x = v[i];

		while (x!=0)
		{
			og=og*10+x%10;
			x=x/10;
		}

		if (v[i] == og)
		{
			for (int j = i; j <= n-1; j++)
				v[j] = v[j+1];
			nr++;
			i--;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';

	cin >> n;
	return 0;
}