
#include <stdio.h>
#include <math.h>
//Se foloseste functia pentru convertirea numerelor din baza 8 in baza zece
long long base_10(long long n)
{
	int k = 0, p = 1;
	while (n > 0) {
		int cif = n % 10;
		k += cif * p;
		p *= 8;
		n = n / 10;
	}
	return k;
}

int main(void)
{
	//Initializarea variabilelor
	long long n, ai, bi, ps = 0, i;
	long long a_mx1 = -1, a_mx2 = -1, b_mx1 = -1, b_mx2 = -1;
	double n_a = 0, n_b = 0;
	//norma reprezinta un radical dintr-un numar real
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld%lld", &ai, &bi);
		ai = base_10(ai);//fiecare coordonata este trecuta in baza zece
		bi = base_10(bi);
		ps = ps + (ai * bi);
	 //Daca coordonata se afla intre cele doua maxime, devine al doilea maxim
	 //In cazul in care este mai mare decat primul maxim, devine noul maxim
	 //Al doilea maxim va avea valoarea fostului maxim
		if (ai > a_mx2 && ai < a_mx1) {
			a_mx2 = ai;
		} else if (ai > a_mx1) {
			a_mx2 = a_mx1;
			a_mx1 = ai;
		}

		if (bi > b_mx2 && bi < b_mx1) {
			b_mx2 = bi;
		} else if (bi > b_mx1) {
			b_mx2 = b_mx1;
			b_mx1 = bi;
		}

		n_a = n_a + (ai * ai);
		n_b = n_b + (bi * bi);
	}

	printf("%lld\n", ps);
	printf("%lld %lld\n", a_mx2, b_mx2);
	printf("%.7lf %.7lf\n", sqrt(n_a), sqrt(n_b));
	//Se afiseaza produsul, cele doua maxime si normele cu sapte zecimale

	return 0;
}
