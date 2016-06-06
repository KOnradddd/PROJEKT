#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "metrics.h"

#define SIZE 40



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
     printf ("Nie moge otworzyc pliku test.txt do zapisu!\n");
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

	c = (double *)malloc(SIZE*sizeof(double));

    int n=bq-aq;
	double thr[SIZE];
	int s;
	printf("Enter threshold: ");
	for(s=1;s<36;s++)
	{
		scanf("%lf", &thr[s]);
	}


	m_euklidesowa(wektor1, wektor2, c, n);
	m_miejska(wektor1, wektor2, c, n);
	m_dyskretna(wektor1, wektor2, c, n);
	m_kolejowa(wektor1, wektor2, c, n);
	m_xn(wektor1, wektor2, c, n);
	m_ham(wektor1, wektor2, c, n);
	m_can(wektor1, wektor2, c, n);
	m_ssd(wektor1, wektor2, c, n);
	m_mae(wektor1, wektor2, c, n);
	m_cos(wektor1, wektor2, c, n);
	m_bc(wektor1, wektor2, c, n);
	soersen(wektor1, wektor2, c, n);
    gower(wektor1, wektor2, c, n);
    soergel(wektor1, wektor2, c, n);
    kulcz(wektor1, wektor2, c, n);
    lorentz(wektor1, wektor2, c, n);
    inter(wektor1, wektor2, c, n);
    noninter(wektor1, wektor2, c, n);
    wave(wektor1, wektor2, c, n);
    motyka(wektor1, wektor2, c, n);
    ruzicka(wektor1, wektor2, c, n);
    tani(wektor1, wektor2, c, n);
    dice(wektor1, wektor2, c, n);
    bhatta(wektor1, wektor2, c, n);
    hell(wektor1, wektor2, c, n);
    matu(wektor1, wektor2, c, n);
    se(wektor1, wektor2, c, n);
    sc(wektor1, wektor2, c, n);
    schi(wektor1, wektor2, c, n);
    ps(wektor1, wektor2, c, n);
    dive(wektor1, wektor2, c, n);
    clark(wektor1, wektor2, c, n);
    adsi(wektor1, wektor2, c, n);
    kl(wektor1, wektor2, c, n);
    jeffreys(wektor1, wektor2, c, n);
    kdiv(wektor1, wektor2, c, n);

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
	printf("\n");
	free(wektor1);
	free(wektor2);
	free(c);
}
