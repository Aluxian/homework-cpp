#include <iostream>
using namespace std;

int main()
{
	int n, d;
	cin >> n;
	int *v = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];

		if (i == 0)
			d = v[0];

		int a = d,
			b = v[i];
		
		while (a != b)
		{
		    if (a > b)
		    	a -= b;
		    else
		    	b -= a;
		}

		d = a;
	}

	cout << "cmmdc: " << d;
	cin >> n;
	return 0;
}