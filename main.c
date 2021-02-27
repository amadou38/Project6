#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 int main()
{
	int  NV1, NV2, NV3, NV4, NV5, NV6;			//Les tailles des vecteurs du fichier Donnees.dat
	int nl1, nl2, nl3, nl4, nl5, nl6, nl7, nc1, nc2, nc3, nc4, nc5, nc6, nc7;//Les tailles des matrices du fichier Donnees.dat
	double **A, *b, *x, **L;	// les elements a utiliser
	int N;
	double  *V1, *V2, *V3, *V4, *V5, *V6, **M1, **M2, **M3, **M4, **M5, **M6, **M7;//Les matrices & vecteurs du fichier Donnees.dat
	double *TableauReel(int ig,int id);	
	double **MatriceReelle( int lg, int ld, int cg, int cd);
	double* RemplirVect(FILE *pfichier, int *NV);
	double **RemplirMatr(FILE *pfichier, int *l, int *c);
	void AfficherMatriceReelle(double **A, int lg, int ld, int cg, int cd);
	void AfficherTableauReel(double *T, int ig, int id);
	void AfficherTabglob(double *V[], int NV[]);
	void AfficherMatriceRglob(double **M[], int nl[], int nc[]);
	char *meth1[6]={"A","Gauss","Gauss Pivot Partiel","Gauss Pivot Total","Decomposition L U","Cholesky"};
//	char *meth2[4]={"A","Jacobi","Gauss-Seidel","SOR"};
	int choix, i, j, choixv, choixmat;
	void entete();
	void DonUtilisateurs(double ***A, double **b, int *N);
	void methodes(double **A, double **L, double *b, double *x, int N);
	int chtype;

	entete();
	printf("\n<1>\t Pour donner la matrice et le vecteur a utiliser \n<2>\t Pour utiliser le fichier Donnees.dat\n");
	printf("Choisissez: <1-2>? ");
	scanf("%d",&chtype);
	if(chtype==2)
	{
		char fichier[30];
		printf("Saisir le nom du fichier de données: ");
		scanf("%s", fichier); system("clear");
		printf("Le nom du fichier est: %s\n\n", fichier);	
		FILE *pfichier;
		pfichier=fopen(fichier,"r");
		V1=RemplirVect(pfichier, &NV1);
		V2=RemplirVect(pfichier, &NV2);
		M1=RemplirMatr(pfichier, &nl1, &nc1);
		M2=RemplirMatr(pfichier, &nl2, &nc2);
		V3=RemplirVect(pfichier, &NV3);
		V4=RemplirVect(pfichier, &NV4);
		V5=RemplirVect(pfichier, &NV5);
		M3=RemplirMatr(pfichier, &nl3, &nc3);
		M4=RemplirMatr(pfichier, &nl4, &nc4);
		V6=RemplirVect(pfichier, &NV6);
		M5=RemplirMatr(pfichier, &nl5, &nc5);
		M6=RemplirMatr(pfichier, &nl6, &nc6);
		M7=RemplirMatr(pfichier, &nl7, &nc7);
		fclose(pfichier);
		 double *V[]={V1,V1,V2,V3,V4,V5,V6};
		double **Mat[]={M1,M1,M2,M3,M4,M5,M6,M7};
		int NV[]={NV1,NV1,NV2,NV3,NV4,NV5,NV6};
		int nl[]={nl1,nl1,nl2,nl3,nl4,nl5,nl6,nl7};
		int nc[]={nc1,nc1,nc2,nc3,nc4,nc5,nc6,nc7};	
	printf("Les matrices disponibles sont:\n");	AfficherMatriceRglob(Mat, nl,nc);
	printf("choix <1-6>? ");
	scanf("%d", &choixmat); system("clear");
	printf("Les vecteurs disponibles sont: \n");	AfficherTabglob(V, NV);
	do
	{
		printf("La taille du vecteur doit etre %d\n", nl[choixmat+1]);
		printf("choix <1-6>? ");
		scanf("%d",&choixv);
	} while(nl[choixmat+1]!=NV[choixv]);
	N=NV[choixv];	
	A=Mat[choixmat+1];
	b=TableauReel(1,N);
	b=V[choixv];
	}
	if(chtype==1)
	{	
		DonUtilisateurs(&A, &b, &N);
	}
	x=TableauReel(1,N); system("clear");
	printf("Les données du systeme lineaire sont:\n");
	printf("L'ordre de la matrice N= %d\n", N);
	printf("La matrice A est: \n"); 	AfficherMatriceReelle(A, 1, N, 1, N);//Affichage de la matrice a utiliser
	printf("Le vecteur b est:\n");		AfficherTableauReel(b, 1, N);		//Affichage du vecteur a uliser
	printf("Choisissez le type de resolution du systeme Ax=b\n");
	printf(" <1>\t Methode directe\n");
	printf(" <2>\t Methode iterative\n");
	printf(" Choix <1-2>? ");
	scanf("%d",&choix); system("clear");
	if(choix==1)
	{
		methodes(A, L, b, x, N);
	}
return 0;
}
	
		
