#include<stdio.h>
#include<stdlib.h>
#include<math.h>

  void GaussPT (double **A, double *b, double *x, int N, double *det)
{
	int i, j, k, Nbpermutation=0, m;
	double pivot, aide, Som, coef, piv=0;
	void AffichTableauResul(double *T, int ig, int id);
	int *TableauEntier(int ig,int id);
	int *T;
	int q, p;
	T=TableauEntier(1,N);
	for(i=1; i<=N; i++)
		T[i]=i;
	
	for(k=1; k<=N-1; k++) // la recherche du max
	{
		aide=fabs(A[k][k]);
		p=k;
		q=k;
       		for(i=k;i<=N;i++)
		for(j=k;j<=N;j++)
		{    
			if(aide<fabs(A[i][j]))
			{
				aide=fabs(A[i][j]);
                  		p=i;
           	  		q=j;
			}
		}
        	for(j=1;j<=N;j++)
        	{
			aide=A[k][j];
			A[k][j]=A[p][j];
			A[p][j]=aide;
			if(k!=p)
				Nbpermutation++;
			
		}
        	for(i=1;i<=N;i++)
		{
			aide=A[i][k];
			A[i][k]=A[i][q];
			A[i][q]=aide;
			if(k!=q)	
				Nbpermutation++;
		}
	    	aide=b[k];
		b[k]=b[p];
		b[p]=aide;
		aide=T[k];
		T[k]=T[q];
		T[q]=aide;		
		pivot=A[k][k];
		printf("%f", pivot);
		if(pivot==0)
		{
			printf("Pas de solution!!!\n");
				exit(-1);
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
	x[T[N]]=b[N]/A[N][N];
	for(i=N-1; i>=1; i--)
	{
		Som=0;
		for(j=i+1; j<=N; j++)
			Som+=A[i][j]*x[T[j]];
		x[T[i]]=(b[i]-Som)/A[i][i];
	}
	*det=1;
	for(i=1; i<=N; i++)
		*det*=A[i][i];
	*det*pow(-1, Nbpermutation);
}

