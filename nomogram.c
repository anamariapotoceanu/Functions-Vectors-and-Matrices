//Potoceanu Ana-Maria 321CA
#include <stdio.h>
#define NR 500

//Functie pentru citirea restrictiilor pentru linie
void read_row(int n, int row[NR][NR])
{
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%d", &row[i][0]);
		for (j = 1; j <= row[i][0]; j++)
			scanf("%d", &row[i][j]);
	}
}

//Functie pentru citirea restrictiilor pentru coloana
void read_col(int m, int col[NR][NR])
{
	int i, j;
	for (i = 0; i < m; i++) {
		scanf("%d", &col[i][0]);
		for (j = 1; j <= col[i][0]; j++)
			scanf("%d", &col[i][j]);
	}
}

//Functie pentru citirea matricei
void read_matrix(int n, int m, int matrix[NR][NR])
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &matrix[i][j]);
}

//Functie care verifica daca este incalcata sau nu o restrictie pentru linie
int verify_row(int group[NR], int nr, int row[NR][NR], int i)
{
	for (int k = 0; k < nr; k++)
		if (group[k] != row[i][k + 1])
			return 0;
	return 1;
}

//Functie care verifica daca este incalcata sau nu o restrictie pentru linie
int verify_col(int group[NR], int nr, int col[NR][NR], int j)
{
	for (int k = 0; k < nr; k++)
		if (group[k] != col[j][k + 1])
			return 0;
	return 1;
}

//Functie pentru verificarea validitatii unui rand
int check_row(int n, int m, int matrix[NR][NR], int row[NR][NR])
{
	int i, j;
	int group[NR];
	for (i = 0; i < n; i++) {
		int k = 0;
		for (j = 0; j < m; j++) {
			int nr_1 = 0;
			//In cazul in care elementul este 0
			//Vom cauta cautarea pana cand intalnim un element egal cu 1
			for (; !matrix[i][j] && j < m; j++)
				;
			//Daca gasim un element de 1, vom numara cati de 1 avem alaturati
			for (; matrix[i][j] && j < m; j++, nr_1++)
				;
			//Retinem intr-un vector dimensiunile grupurilor de casute colorate
			group[k++] = nr_1;
		}
		//Verificam daca una dintre conditiile pentru rand a fost incalcata
		if (!verify_row(group, row[i][0], row, i))
			return 0;
	}

	return 1;
}

int check_col(int n, int m, int matrix[NR][NR], int col[NR][NR])
{
	int i, j;
	int group[NR];
	for (j = 0; j < m; j++) {
		int k = 0;
		for (i = 0; i < n; i++) {
			int nr_1 = 0;
	//Vom ignora elementele de zero, pana cand ajungem la un element de 1
			for (; !matrix[i][j] && i < n; i++)
				;
			for (; matrix[i][j] && i < n; i++, nr_1++)
				;
		//Retinem intr-un vector dimensiunea grupurilor de casute colorate
			group[k++] = nr_1;
		}
		//Verificam daca una dintre conditiile pentru coloana a fost incalcata
		if (!verify_col(group, col[j][0], col, j))
			return 0;
	}

	return 1;
}

//Functie care afiseaza, in final, mesajul dorit
void corect(int n, int m, int matrix[NR][NR], int row[NR][NR], int col[NR][NR])
{
	if (check_row(n, m, matrix, row) && check_col(n, m, matrix, col))
		printf("Corect\n");
	else
		printf("Eroare\n");
}

int main(void)
{
	int row[NR][NR], col[NR][NR], matrix[NR][NR], t, n, m;
	scanf("%d", &t);
	while (t--) {
		//Se citesc datele necesare
		scanf("%d%d", &n, &m);
		read_row(n, row);
		read_col(m, col);
		read_matrix(n, m, matrix);
		//Se afiseaza mesajul dorit
		corect(n, m, matrix, row, col);
	}
	return 0;
}
