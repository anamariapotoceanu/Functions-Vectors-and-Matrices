//Potoceanu Ana-Maria 321CA
#include <stdio.h>
#include <string.h>
#define MAX 1000
#define NMAX 25
#define NR 26
//Functia pentru afisarea coordonatei coloanei, asemenea foii Excel.
void coord(int k)
{
	char s[NMAX];
	int i = 0;
	char c;
	if (k < NR) {//Se afiseaza literele de la A la Z
		c = 'A' + k % NR;//Aflam litera corespunzatoare cu ajutorul restului.
		printf("%c", c);
	}
	if (k >= NR) {
		//Se afiseaza caracterele corespunzatoare pentru Microsoft Excel.
		c = 'A' + k / NR - 1;//Prima litera se afla cu ajutorul catului.
		s[i] = c;//Se va retine prima litera cu ajutorul unui sir de caractere.
		i++;//Crestem i pentru a putea afla cea de-a doua litera.
		c = 'A' + k % NR;//Urmatoarea litera o aflam folosind restul.
		s[i] = c;
		printf("%s", s);//Se afiseaza sirul cu literele corespunzatoare.
	}
}

int main(void)
{
	int n, i, j, ap[MAX][MAX] = {0}, a[MAX][MAX];
	unsigned long d = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	i = 0, j = 0;//Pornim din patratul din stanga-sus.
	while (a[i][j] != 0 && ap[i][j] == 0) {
		ap[i][j] = 1;//Retinem faptul ca patratul respectiv a fost parcurs.
		if (a[i][j] > 0)
			d += a[i][j];//Calculam distanta parcursa.
		else
			d -= a[i][j];
		//Se verifica daca patratul este alb sau negru.
		if ((i + j) % 2 == 0) {
			j = j + a[i][j];
			//Daca patratul este alb, mutarea se face pe linie.
			if (j > n - 1)
				j = (j % n) % n;
			//Aflam indicele coloanei daca se iese din careu.
			if (j < 0)
				j = (j % n + n) % n;
		} else {
			i = i + a[i][j];
			//Daca patratul este negru, mutarea se face pe coloana.
			if (i > n - 1)
				i = (i % n) % n;//Aflam indicele liniei, daca se iese din careu
			if (i < 0)
				i = (i % n + n) % n;
		}
	}
	printf("%lu\n", d);//Se afiseaza distanta parcursa.
	printf("%d ", n - i);//Se afiseaza coordonata pentru linie
	coord(j);//Se apeleaza functia pentru a afisa coordonata pentru coloana.
	printf("\n");

	return 0;
}
