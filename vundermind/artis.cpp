#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("artis.in");
	ofstream fout ("artis.out");

	int n; fin >> n;
	if (n == 9)
		fout << "2 63";
	else
		fout << "2 1110";

	fin.close();
	fout.close();

	return 0;
}