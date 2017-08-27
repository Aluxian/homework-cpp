#include <iostream>
using namespace std;

int main()
{
	int n, a, b, c; cin >> n >> a >> b >> c;
	float s = -b/a;

	if (n == 0)
		s = 2;
	else if (n != 1)
		for (int i = 2; i <= n; ++i)
		{
			s = (-c - b*s) / a;
		}

	cout << s;
	return 0;
}