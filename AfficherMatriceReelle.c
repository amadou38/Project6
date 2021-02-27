#include<stdio.h>
#include<stdlib.h>
 
 void AfficherMatriceReelle(double **A, int lg, int ld, int cg, int cd)
{
 int i,j;
     for(i=lg; i<=ld; i++)
   {	for(j=cg; j<=cd; j++)
       	  printf("%2.0f  ", A[i][j]);
	printf("\n");
     } 
 }
