#include <iostream>
using namespace std;

int main()
{
	// 1 121 12321 tadam :)

	// deci fiecare grupa o formezi asa
	// de la 1 la i
	// apoi de la i-1 la 1

	int n = 7;
	int c = 1;

	int ok = 1;

	for(int i=1; ok == 1; i++)
	{
		// de la 1 la i
		for (int j = 1; j <= i; j++)
			if (c == n)
			{
				ok = 0;
				cout << j;
			}

		// de la i-1 la 1
		for (int j = i-1; j >= 1; j--)
			if (c == n)
			{
				ok = 0;
				cout << j;
			}
	}

	return 0;
}