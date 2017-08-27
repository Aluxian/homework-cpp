#include <iostream>
using namespace std;

int main()
{
	// 1 12 123 1234 
	
	int n = 7;
	int c = 1;

	int ok = 1;

	for(int i=1; ok == 1; i++)
	{
		for(int j=1;j<=i && ok == 1;j++)//bravoa
		{
			if (c == n)
			{
				ok = 0;
				cout << j;
			}

			c++;
		}
	}

	return 0;
}