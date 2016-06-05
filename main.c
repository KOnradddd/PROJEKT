#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "metrics.h"

#define SIZE 13



int main()
{
    double tab[300][300];
	int aq=random(0,300);
	int bq=random(0,300);
	int cq=random(0,300);
	int dq=random(0,300);

	if(aq>bq)
	{
		int w=aq;
		aq=bq;
		bq=w;
	}
	if(cq>dq)
	{
		int w=cq;
		cq=dq;
		dq=w;
	}


	double *wektor1=(double*)malloc((bq-aq+1)*sizeof(double));
    double *wektor2=(double*)malloc((bq-aq+1)*sizeof(double));

	FILE *fp;
   if ((fp=fopen("dane.txt", "a+"))==NULL)
   {
     printf ("Nie mogê otworzyæ pliku test.txt do zapisu!\n");
     exit(1);
   }

   int i,j;

   for(i=0;i<300;i++)
   {
	   for(j=0;j<300;j++)
	   {
			fscanf (fp, "%lf", &tab[i][j]);
	   }
   }

   for(i=cq;i<dq;i++)
   {
	   wektor1[aq]=tab[aq][i];
   }
   for(i=cq;i<dq;i++)
   {
	   wektor2[bq]=tab[bq][i];
   }


	double *c;
	double *d_a, *d_b;

	c = (double *)malloc(SIZE*sizeof(double));

    int n=bq-aq;
	double thr[SIZE];
	printf("Enter Threshold: ");
	int s;
	for(s=1;s<36;s++)
	{
		thr[s]=1;
	}


	m_euklidesowa(d_a, d_b, c, n);
	m_miejska(d_a, d_b, c, n);
	m_dyskretna(d_a, d_b, c, n);
	m_kolejowa(d_a, d_b, c, n);
	m_xn(d_a, d_b, c, n);
	m_ham(d_a, d_b, c, n);
	m_can(d_a, d_b, c, n);
	m_ssd(d_a, d_b, c, n);
	m_mae(d_a, d_b, c, n);
	m_cos(d_a, d_b, c, n);
	m_bc(d_a, d_b, c, n);
	soersen(d_a, d_b, c, n);
    gower(d_a, d_b, c, n);
    soergel(d_a, d_b, c, n);
    kulcz(d_a, d_b, c, n);
    lorentz(d_a, d_b, c, n);
    inter(d_a, d_b, c, n);
    noninter(d_a, d_b, c, n);
    wave(d_a, d_b, c, n);
    motyka(d_a, d_b, c, n);
    ruzicka(d_a, d_b, c, n);
    tani(d_a, d_b, c, n);
    dice(d_a, d_b, c, n);
    bhatta(d_a, d_b, c, n);
    hell(d_a, d_b, c, n);
    matu(d_a, d_b, c, n);
    se(d_a, d_b, c, n);
    sc(d_a, d_b, c, n);
    schi(d_a, d_b, c, n);
    ps(d_a, d_b, c, n);
    dive(d_a, d_b, c, n);
    clark(d_a, d_b, c, n);
    adsi(d_a, d_b, c, n);
    kl(d_a, d_b, c, n);
    jeffreys(d_a, d_b, c, n);
    kdiv(d_a, d_b, c, n);

int wynik[SIZE];

	for(i=0;i<36;i++)
	{
		if(thr[i]<c[i])
		{
			wynik[i]=1;
		}
		else
		{
			wynik[i]=0;
		}
	}

	for(i=0;i<36;i++)
	{
		printf("%d ",wynik[i]);
	}

	free(wektor1);
	free(wektor2);
	free(c);


	return 0;
}
