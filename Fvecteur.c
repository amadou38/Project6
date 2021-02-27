#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double *RemplirVect(FILE *pfichier, int *NV)
{
	 double *V;
double *TableauReel(int ig,int id);

int i;
char car='1';
	if(pfichier==NULL) 
	{
  		printf("\nOuverture du fichier impossible");
  		exit(-1);
	}
	
	
	fscanf(pfichier,"%d",NV);
  	while(car!='\n')
	{
		fscanf(pfichier,"%c",&car);
	}
	V=TableauReel(1,*NV);
	fscanf(pfichier,"%lf",&V[1]);
	car='1';
	while(car!='\n')
	{
		car=fgetc(pfichier);
	}
	for(i=2;i<=*NV;i++)
	{
 		fscanf(pfichier,"%lf",&V[i]);
	}
	return V-0;
}
