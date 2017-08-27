#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int *v = new int[n];
	int *w = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if (i != 0 && v[i-1] > v[i])
			return 0;
	}

	for (int i = 0; i < n/2; ++i)
	{
		int aux = v[i];
		v[i] = v[n-i-1];
		v[n-i-1] = aux;
	}

	for (int i = 0; i < n; ++i)
		cout << v[i];

	cin >> n;
	return 0;
}