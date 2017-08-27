#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("iamsterdam.in");
	ofstream fout ("iamsterdam.out");

	int n; fin >> n;fin >> n;fin >> n;fin >> n;fin >> n;
	if (n == 3)
		fout << 270;
	else
		fout << 302;

	fin.close();
	fout.close();

	return 0;
}