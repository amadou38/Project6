#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double **RemplirMatr(FILE *pfichier, int *l, int *c)
{
	double **M;
double **MatriceReelle( int lg, int ld, int cg, int cd);

int i, j;
char car='1';
	if(pfichier==NULL) 
	{
  		printf("\nOuverture du fichier impossible");
  		exit(-1);
	}

	
	fscanf(pfichier,"%d",l);
	fscanf(pfichier,"%d",c);
  	while(car!='\n')
	{
		fscanf(pfichier,"%c",&car);
	}
	M=MatriceReelle(1,*l, 1, *c);
	for(j=1; j<=*l; j++)
	{
		for(i=1;i<=*c;i++)
		fscanf(pfichier,"%lf",&M[j][i]);
		car='1';
		while(car!='\n')
		{
			car=fgetc(pfichier);
		}
	}	
return M;
}
