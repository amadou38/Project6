#include <stdio.h>
#include <stdlib.h>

int *TableauEntier(int ig,int id)
{
	int *T;
	T=(int*)malloc((id-ig+1)*sizeof(int));
	if(T==NULL){
		printf(" Tableau entier : pas assez de memoire \n");
		exit(-1);
	}
	return T-ig;
}

