#include<stdio.h>
#include<stdlib.h>
	
	void methodes(double **A, double **L, double *b, double *x, int N)
	{
		void Gauss (double **A, double *b, double *x, int N, double *det);
		void GaussPP (double **A, double *b, double *x, int N, double *det);
		void GaussPT (double **A, double *b, double *x, int N, double *det);
		void DecomposeLU (double **A, double **L, int N);
		double *TableauReel(int ig,int id);
		double **MatriceReelle( int lg, int ld, int cg, int cd);
		double *y, det, detL, detU;
		int choixm, i;
		char *meth1[6]={"A","Gauss","Gauss Pivot Partiel","Gauss Pivot Total","Decomposition L U","Cholesky"};
		printf("Vous avez choisi de resoudre le systeme lineaire par une methode directe.\n");
		printf("Choisissez une methode parmi les methodes suivantes:\n");
		for(i=1; i<=5; i++)
			printf(" <%d>\t Methode de %s\n", i, meth1[i]); //les methodes
		printf("Choix <1-5>? ");
		scanf("%d",&choixm); system("clear");
		printf("Vous avez choisi la methode de %s pour resoudre le systeme Ax=b.\n", meth1[choixm]);
		switch(choixm)
		{
			case 1:
				Gauss (A, b, x, N, &det);
				printf("Le determinant de cette matrice est det(A)= %f\n", det);
				printf("La solution du système est: \n");
				AffichTableauResul(x, 1, N);
		 		break;
			case 2:
				GaussPP (A, b, x, N, &det);
				printf("Le determinant de cette matrice est det(A)= %f\n", det);
				printf("La solution du système est: \n");
				AffichTableauResul(x, 1, N);
		 		break;
			case 3:
				GaussPT (A, b, x, N, &det);
				printf("Le determinant de cette matrice est det(A)= %f\n", det);
				printf("La solution du système est: \n");
				AffichTableauResul(x, 1, N);
		 		break;
			case 4:
				L=MatriceReelle(1,N,1,N);
				DecomposeLU (A, L, N);
				printf("La matrice L:\n");
				AfficherMatriceReelle(L, 1, N, 1, N); 
				printf("\nLa matrice U:\n");
				AfficherMatriceReelle(A, 1, N, 1, N); printf("\n");
				y=TableauReel(1,N);
				Gauss (L, b, y, N, &det); 	detL=det;
				printf("Le determinant de cette matrice est det(L)= %f\n", detL);
				//printf("La solution du système est: \n");
				//AffichTableauResul(y, 1, N);
				Gauss (A, y, x, N, &det);	detU=det;
				printf("Le determinant de cette matrice est det(U)= %f\n", detU);
				printf("La solution finale du système est: \n");
				AffichTableauResul(x, 1, N);
				det= detU*detL;
				printf("Le determinant de cette matrice est det(A)= %f\n", det);
		 		break;
			case 5:
		 		break;
			default: printf("Choix erronne!!!\n");
		}
	}
	
