#include <fstream>
#include <iostream>
#include <string>
using namespace std;

char char_types[3];
int lastX = -1;
int index = 0;
int row[1000];

string combine_chars(char c1, char c2)
{
	string str;

	if (c1 == c2)
		str = &c1+c2;

	else if (c1 == char_types[0])
		if (c2 == char_types[1])
			str = char_types[2];
		else
			str = char_types[1];

	else if (c1 == char_types[1])
		if (c2 == char_types[0])
			str = char_types[2];
		else
			str = char_types[0];

	else if (c1 == char_types[2])
		if (c2 == char_types[1])
			str = char_types[0];
		else
			str = char_types[1];

	return str;
}

int getPossNo(string str)
{
	int n = -1;
	char lastChar = '0';

	while (str != "")
	{
		if (str.at(0) != lastChar)
		{
			n++;
			lastChar = str.at(0);
		}
		
		str = str.substr(1);
	}

	return n;
}

void doPoss(string str, int x)
{
	int pos = getPossNo(str);

	if (pos == 0)
	{
		row[index] = str.length();
		return;
	}

	for (int i = 0; i < pos; i++)
	{
		while (str.at(i) == str.at(i+1))
		{
			i++;
			pos++;
		}

		string nstring = "";

		for (int j = 0; j < i; j++)
			nstring += str.at(j);
		nstring += combine_chars(str.at(i), str.at(i+1)) + str.substr(i+2);

		
		if (x <= lastX)
			index++;
		lastX = x;
		
		row[index]++; doPoss(nstring, x+1);
	}
}

int main()
{
	ifstream fin ("cristale.in");
	ofstream fout ("cristale.out");

	fin >> char_types[0];
	fin >> char_types[1];
	fin >> char_types[2];

	int p;
	fin >> p;

	string char_lines[p+1];

	for (int i = 1; i <= p; i++)
	{
		int n;
		fin >> n;
		char_lines[i] = "";

		for (int j = 1; j <= n; j++)
		{
			char c; fin >> c;
			char_lines[i] += c;
		}
	}

	for (int i = 1; i <= p; i++)
	{
		string str = char_lines[i];
		
		row[index]++; doPoss(str, 1);

		int lowest = str.length();
		for (int i = 0; i <= index; i++)
			if (lowest > row[i])
				lowest = row[i];

		index = 0;
		fout << lowest << "\n";
	}

	fin.close();
	fout.close();

	return 0;
}