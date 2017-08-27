#include <iostream>
using namespace std;

int main()
{
	int x = 12,
		y = 23,
		s = 0;

	if (x%2 != 0)
		x++;

	for (int i = x; i <= y; i+=2)
		s+=i;

	cout << s;

	cin >> x;
	return 0;
}