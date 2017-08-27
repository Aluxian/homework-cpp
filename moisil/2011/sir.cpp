#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("sir.in");
	ofstream fout ("sir.out");

	int X[1001], A, B, M, Q;
	fin >> X[0] >> A >> B >> M >> Q;

	for (int i = 1; i <= Q; i++)
		fin >> X[i];

	for (int i = 1; i <= Q; i++)
	{
		int n = (A * X[i-1] + B) % M;
		fout << n << endl;
	}
	
	fin.close();
	fout.close();

	return 0;
}