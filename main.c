#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "array.h"

#define SIZE 13



int main()
{
	hello_message();
	double *a, *b, *c;

	printf("Podaj liczbe wspolrzednych: ");
	int n;
	scanf("%d",&n);
	a = (double *)malloc(n*sizeof(double));
	b = (double *)malloc(n*sizeof(double));
	c = (double *)malloc(SIZE*sizeof(double));



	printf("\nDla punktu A: ");
	for( int i = 0; i < n; ++i )
	{
		scanf("%lf",&a[i]);
	}

	printf("Dla punktu B: ");
	for( int i = 0; i < n; ++i )
	{
		scanf("%lf",&b[i]);
	}
	printf("\n");


	m_euklidesowa(a,b,c,n);
	m_miejska(a,b,c,n);
	m_dyskretna(a,b,c,n);
	m_kolejowa(a,b,c,n);
	m_xn(a,b,c,n);
	m_ham(a,b,c,n);
	m_can(a,b,c,n);
	m_ssd(a,b,c,n);
	m_mae(a,b,c,n);
	m_cos(a,b,c,n);
	m_bc(a,b,c,n);



	printf("Metryka Euklidesowa: %lf\n",c[1]);
	printf("Metryka miejska: %lf\n",c[2]);
	printf("Metryka dyskretna: %lf\n",c[3]);
	printf("Metryka kolejowa: %lf\n",c[4]);
	printf("Metryka w przestrzeni X^N: 1/ %lf\n",c[5]);
	printf("Metryka Hamminga: %lf\n",c[6]);
	printf("Metryka Canberra: %lf\n",c[7]);
	printf("Metryka sum roznic kwadratow: %lf\n",c[8]);
	printf("Metryka Mean absolute error: %lf\n",c[9]);
	printf("Metryka Cosine similarity: %lf\n",c[10]);
	printf("Metryka Bray-Curtis: %lf\n",c[11]);




	free(a);
	free(b);
	free(c);



	return 0;
}
