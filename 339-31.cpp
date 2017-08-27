#include <iostream>
using namespace std;

int main()
{
	int n = 11, *v = new int[n];

	for (int i = 0; i <= 2; ++i)
		for (int j = i; j < n; j += 3)
			v[j] = i;

	for (int i = 0; i < n; ++i)
		cout << v[i] << ' ';

	return 0;
}