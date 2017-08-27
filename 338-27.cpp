#include <iostream>
using namespace std;

int main()
{
	int n, m, v[101], x;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	for (int pozitie = 1; pozitie <= n; pozitie += m*m) {
		for (int rand = pozitie/3; rand < m; rand++) {
			for (int coloana = 1; coloana <= m; coloana++) {
                cout << v[pozitie] << ' ';
                pozitie++;
			}

			cout << endl;
		}

		cout << "poz:" << pozitie << endl;
		cout << "Apasaaaaaaaaaa pentru pagina urm";
		cin >> x;

	}
cin>>x;
	return 0;

}