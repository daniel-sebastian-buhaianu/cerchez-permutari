#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "n = "; cin >> n;

	int i, p[n+1];

	for (i = 1; i <= n; i++)
	{
		p[i] = i;
	}

	int gata = 0, j, aux;

	while (!gata)
	{
		// afisam configuratia curenta

		for (i = 1; i <= n; i++)
		{
			cout << p[i] << ' ';
		}

		cout << '\n';

		// generam configuratia urmatoare

		for (i = n-1; i > 0 && p[i] > p[i+1]; i--);

		if (i == 0)
		{
			gata = 1; // ultima configuratie
		}
		else
		{
			// determin cea mai mica valoare > p[i]

			for (j = n; p[j] < p[i]; j--);

			// interschimb p[i] cu p[j]

			aux = p[i];
			p[i] = p[j];
			p[j] = aux;

			// inversez elementele de pe pozitiile i+1...n

			for (i = i+1, j = n; i < j; i++, j--)
			{
				aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
		}
	}

	return 0;
}
