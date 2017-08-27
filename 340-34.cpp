#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int tmax = 0,
		max = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;

		if (x%2 == 0)
			tmax++;
		else
		{
			if (tmax > max)
				max = tmax;
			tmax = 0;
		}
	}

	cout << max;

	cin >> n;
	return 0;
}