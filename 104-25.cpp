#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a = 1844657,
		b = 3;

	cout << a / (int) pow(10, b) * (int) pow(10, b);
	return 0;
}