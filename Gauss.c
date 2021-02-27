#include<stdio.h>
#include<stdlib.h>
#include<math.h>

  void Gauss (double **A, double *b, double *x, int N, double *det)
{
	int i, j, k, Nbpermutation, m;
	double pivot, aide, Som, coef;
	void AffichTableauResul(double *T, int ig, int id);
	for(k=1; k<=N-1; k++)
	{
		pivot=A[k][k];
		if(pivot==0)
		{
			m=k+1;
			while(A[m][k]==0 && m<=N)
				m++;
			if (m>N)
			{
				printf("Matrice pas inversible!!!\n");
				exit(-1);
			}
			for(j=1; j<=N; j++)
			{
				aide=A[k][j];
				A[k][j]=A[m][j];
				A[m][j]=aide;
			}
			aide=b[k];
			b[k]=b[m];
			b[m]=aide;
			Nbpermutation++;
			pivot=A[k][k];
		}
		for(i=k+1; i<=N; i++)
		{
			coef=A[i][k]/pivot;
			for(j=k+1; j<=N; j++)
				A[i][j]=A[i][j]-coef*A[k][j];
			b[i]=b[i]-coef*b[k];
		}
	}
	if(A[N][N]==0)
	{
		printf(" Matrice pas inversible!!!\n");
		exit(-1);
	}
	x[N]=b[N]/A[N][N];
	for(i=N-1; i>=1; i--)
	{
		Som=0;
		for(j=i+1; j<=N; j++)
			Som+=A[i][j]*x[j];
		x[i]=(b[i]-Som)/A[i][i];
	}
	*det=1;
	for(i=1; i<=N; i++)
		*det*=A[i][i];
	*det*pow(-1, Nbpermutation);
}

