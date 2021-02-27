#include<stdio.h>
#include<stdlib.h>
 
 void AfficherTableauReel(double *T, int ig, int id)
{
 int i;
 for(i=ig; i<=id; i++)
 printf("%2.0f  ", *(T+i));
printf("\n"); 
 }
