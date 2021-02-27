#include<stdio.h>
#include<stdlib.h>
#include<math.h>

  void DecomposeLU (double **A, double **L, int N)
{		
	int i,j,k;


	for(k=1; k<=N-1; k++)
	{
		for(i=1; i<=k-1; i++)	
			L[i][k]=0;
		L[k][k]=1;
		for(i=k+1; i<=N; i++)	
		L[i][k]=A[i][k]/A[k][k];
		for(i=k+1; i<=N; i++)
		{
			for(j=1; i<=k; j++)
				A[i][j]=0;
		}
		for(i=k+1; i<=N; i++)
		{
			for(j=1; j<=k; j++)
				A[i][j]=A[i][j]-L[i][k]*A[k][j];
		}
	}
	for(i=1; i<=N-1; i++)
		L[i][N]=0;
	L[N][N]=1;
}
