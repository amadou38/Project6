#include<stdio.h>
#include<stdlib.h>
	
	void DonUtilisateurs(double ***A, double **b, int *N)
	{
		int i, j;
		double *TableauReel(int ig,int id);	
		double **MatriceReelle( int lg, int ld, int cg, int cd);
		double *z, **B;
		printf("Donner la taille:");
		scanf("%d", N);
		B=MatriceReelle( 1, *N, 1, *N);
		z=TableauReel(1,*N);
		printf("Les donnees de la matrice:\n");
		for(i=1; i<=*N; i++)
		{	printf("La ligne %d: \n",i);
			for(j=1; j<=*N; j++)
				scanf("%lf",&B[i][j]);
		}
		printf("Les donnees du vecteur:\n");
		for(i=1; i<=*N; i++)
		{	
			printf("La composante %d: \n",i);
			scanf("%lf",&z[i]);
		}
		*A=B;
		*b=z;
	}
