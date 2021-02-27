#include<stdio.h>
#include<stdlib.h>

	void entete()
	{
		
		system("clear");
		printf("\t****************************************************************\n\t****************************************************************\n");
		printf("\t\t\t Resolution Numérique de Ax=b\n\n");
		printf("\tAuteurs: DIALLO AMADOU   &   ALOUACH GHIZLANE\n");
		printf("\tFiliere: MIP S4 \n\tAnnee: 2015-2016\n");
		printf("\t****************************************************************\n\t****************************************************************\n");
		printf("On considère un système linéaire Ax=b, A est une matrice carrée d'ordre N et b est un vecteur de taille N.\n");
		printf("Les données: N (dimension de la matrice), A (matrice), b (vecteur), X0 (vecteur), le paramètre Omega, IterMax (nombre maximal d'itérations) et eps (précision) sont stockées dans un fichier.\n");
		printf("La résolution de ce système linéaire sera faite par les méthodes directes et itératives.\n\n");
	
		printf("Appuyer sur la touche <Entree> pour continuer...");
		getchar(); system("clear");
	}
