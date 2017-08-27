#include <iostream>
using namespace std;

int main()
{
	int n, nr = 0;
	cin >> n;
	int v[n+1];

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	for (int i = 1; i <= n; i++)
	{
		if (i%2==0)
        {
            for (int j = i; j < n; j++)
                v[j] = v[j+1];
            n--;
        }
	}

	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';

	return 0;
}
