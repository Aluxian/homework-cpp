#include <iostream>
using namespace std;

int main()
{
	int n = 82,
		p = 3,
		ok = 1,
		pw = 0;

	for (int i = 2; i <= p/2; ++i)
		if (p%i == 0)
			ok = 0;

	if (ok == 1)
	{
		while (n%p == 0)
		{
			n /= p;
			pw++;
		}
	}

	cout << pw;
	cin >> n;
	return 0;
}