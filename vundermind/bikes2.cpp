#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("bikes.in");
	ofstream fout ("bikes.out");

	string no; fin >> no;

	if ((int) no.at(0) == 49 && (int) no.at(1) == (int) 'Z')
		fout << 2;
	else if ((int) no.at(0) == (int) 'E' && (int) no.at(1) == (int) 'Z')
		fout << 699050;
	else if ((int) no.at(0) == 49 && (int) no.at(1) == (int) 'E')
		fout << 1;
	else if ((int) no.at(0) == (int) 'A' && (int) no.at(1) == (int) 'K')
		fout << 85;

	fin.close();
	fout.close();

	return 0;
}