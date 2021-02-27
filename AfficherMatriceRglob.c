#include<stdio.h>
#include<stdlib.h>
 
 void AfficherMatriceRglob(double **M[], int nl[], int nc[])
{
 int i,j, k;
     printf("Nous avons:\n");
 for(i=2; i<=7; i++)
 {	printf("La taille de la matrice M%d: %d %d\n",i-1, nl[i], nc[i]);
	printf("Les éléments de la matrice M%d sont:\n",i-1); 
	for(j=1; j<=nl[i]; j++)
	{
		for(k=1; k<=nc[i]; k++)
		printf("\t%2.0f  ", M[i][j][k]);
		printf("\n");
	}
		getchar();
	printf("\n"); 
  }
 }
