#include<stdio.h>
#include<stdlib.h>
 
 void AffichTableauResul(double *T, int ig, int id)
{
 int i;
 for(i=ig; i<=id; i++)
 printf("X%d=%f  ", i, *(T+i));
printf("\n"); 
 }
