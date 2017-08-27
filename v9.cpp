#include <iostream>
using namespace std;

int main()
{
	int n, nr = 0;
	cin >> n;
	int v[n+1], w[n+1], poz = 1;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	for (int i = 1; i <= n; i++)
	{
		if (v[i] > 0)
        {
            for (int j = i; j <= n-1; j++)
                {
                    w[poz] = v[j];
                    poz++;
                    v[j] = v[j+1];
                }
            n--; i--;
        }
	}

	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';
    cout << endl;
	for (int i = 1; i <= n; i++)
		cout << w[i] << ' ';

	return 0;
}