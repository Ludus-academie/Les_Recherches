

#include <stdio.h>

#define TAILLE 6

int partitionnement(int n_tab[], int n_imin, int n_imax);
void TriRapid(int n_tab[], int n_imin, int n_imax);
void quickSort(int n_tab[], int n);

//recherche dichotomique recursive
int recherche_dichotomique_recursive(int val, int n_tab[], int n_mi);

//recherche dichotomique iterative
int recherche_dichotomique(int n_val, int n_tab[], int n_taille);

//Recherche interpolée
int recherche_interpolee(int T[], int n_imin, int n_imax, int n_x);

int main()
{

	/**************************************************************************************************************/

	//Tris
	//Tri rapide
	int n_tab[TAILLE] = { 6,3,7,2,4,5 };


	quickSort(n_tab, TAILLE);


	//Recherche simple (séquencielle)
	int val = 2;
	int pos_nombre = 0;
	for (int n_i = 0; n_i < 6; n_i++) {
		if (n_tab[n_i] == val) {
			pos_nombre = n_i;
		}
	}


	for (int n_i = 0; n_i < 6; n_i++) {

		printf("%d", n_tab[n_i]);
	}


	//Recherche dichotomique
	int n_i = 0;
	n_i = TAILLE / 2;
	//int recherche = recherche_dichotomique_recursive(10, n_tab, n_i);

	//recherche = recherche_dichotomique(7, n_tab, TAILLE);


	int recherche = recherche_interpolee(n_tab, 0, TAILLE-1, 4);

	return 0;

}

int recherche_dichotomique_recursive(int n_val, int n_tab[], int n_mi) {

	int n_trouve = 0;
	if (n_tab[n_mi] == n_val) {
		return n_mi;
		n_trouve = 1;
	}

	if (n_mi<0 || n_mi>TAILLE) {

		return n_trouve;
	}

	else if (n_tab[n_mi] > n_val) {

		return recherche_dichotomique_recursive(n_val, n_tab, n_mi - 1);
	}
	else {

		return recherche_dichotomique_recursive(n_val, n_tab, n_mi + 1);
	}

}

int recherche_dichotomique(int n_val, int n_tab[], int n_taille) {
	
	int len = n_taille / 2;
	int n_i = len;
	while (n_tab[n_i] != n_val) {

		if (n_tab[n_i] > n_val) {
			n_i--;

		}
		else {
			n_i++;
		}

	}
	return n_i;


}




int partitionnement(int n_tab[], int n_imin, int n_imax) {

	int n_v;
	int n_i;
	int n_j;
	int n_temp;

	n_v = n_tab[n_imax];
	n_i = n_imin;
	n_j = n_imax - 1;

	while (n_i <= n_j) {
		while (n_i < n_imax && n_tab[n_i] <= n_v) {
			n_i = n_i + 1;
		}
		while (n_j >= n_imin && n_tab[n_j] >= n_v) {
			n_j = n_j - 1;
		}
		if (n_i < n_j) {

			n_temp = n_tab[n_i];
			n_tab[n_i] = n_tab[n_j];
			n_tab[n_j] = n_temp;
		}

	}
	n_tab[n_imax] = n_tab[n_i];
	n_tab[n_i] = n_v;

	return n_i;


}


void TriRapid(int n_tab[], int n_imin, int n_imax) {
	int n_i = 0;

	if (n_imin < n_imax) {
		n_i = partitionnement(n_tab, n_imin, n_imax);

		TriRapid(n_tab, n_imin, n_i - 1);
		TriRapid(n_tab, n_i + 1, n_imax);

	}

}


void quickSort(int n_tab[], int n) {
	TriRapid(n_tab, 0, n - 1);
}


//Recherche interpolée
//n_imin indice mini
//n_imax indice maxi
//n_x val à chercher
int recherche_interpolee(int T[], int n_imin, int n_imax, int n_x)
{
	int n_m;
	while (n_imin <= n_imax)
	{
		if (n_x < T[n_imin])
			return -1;
		if (n_x > T[n_imax])
			return -1;
		if (T[n_imin] == T[n_imax])
			return n_imin;
		n_m = (int)(1.0 * (n_x - T[n_imin]) / (T[n_imax] - T[n_imin]) * (n_imax - n_imin) + n_imin);
		if (T[n_m] == n_x)
			return n_m;
		if (T[n_m] < n_x)
			n_imin = n_m + 1;
		else
			n_imax = n_m - 1;
	}
	return -1;
}