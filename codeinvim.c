
#include <stdio.h>
#define NR 500
#define MAX 10

//Functie pentru citirea vectorului cu note
void read_grades(int n, int x[NR])
{
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
}

//Functie pentru citirea vectorului cu punctele credit
void read_credit(int n, int c[NR])
{
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
}

//Functie care determina daca s-a realizat punctajul dorit
int check_p(int p_total, int p_min)
{
	if (p_total == p_min || p_total > p_min)
		return 0;
	return 1;
}

//Functie care sorteaza descrescator vectorul cu mariri
void sort_desc(int grades[NR], int n)
{
	int tmp, i, j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (grades[i] < grades[j]) {
				tmp = grades[i];
				grades[i] = grades[j];
				grades[j] = tmp;
			}
}

//Functie care calculeaza punctajul initial
int product(int x[NR], int c[NR], int n)
{
	int p_total = 0;
	for (int i = 0; i < n; i++) {
		int product = x[i] * c[i];
		p_total += product;
	}
	return p_total;
}

int main(void)
{
	int n, x[NR], c[NR], p_min, grades[NR], p_total;
	//Se citesc datele de la tastatura
	scanf("%d", &n);
	read_grades(n, x);
	read_credit(n, c);
	scanf("%d", &p_min);

	p_total = product(x, c, n);

	//Punem punctajul pentru mariri intr-un vector
	for (int i = 0; i < n; i++)
		grades[i] = c[i] * (MAX - x[i]);

	//Sortam vectorul cu mariri descrescator
	sort_desc(grades, n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		//Adaugam la punctaj cate o marire pana cand obtinem rezultatul dorit
		p_total = p_total + grades[i];
		//Calculam de cate adaugari avem nevoie
		if (!check_p(p_total, p_min)) {
			m++;
			break;
		} else if (check_p(p_total, p_min)) {
			m++;
		}
	}

	//Nu putem realiza punctajul necesar
	if (check_p(p_total, p_min))
		printf("-1\n");

	//Afisam numarul minim de mariri
	printf("%d\n", m);
	return 0;
}
