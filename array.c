#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 13


//Metryka euklidesowa

void m_euklidesowa(double *a, double *b, double *c, int n)
{
	double s=0;
	for(int k=0;k<n;k++)
	{
		s+=(a[k]-b[k])*(a[k]-b[k]);
	}
	c[1]=sqrt(s);
}

//Metryka miejska

void m_miejska(double *a, double *b, double *c, int n)
{
		double s=0;
		for(int k=0;k<n;k++)
		s+=abs(a[k]-b[k]);
		c[2]=s;
}

//Metryka dyskretna

void m_dyskretna(double *a, double *b, double *c, int n)
{
		int q=0, k=0;
		for(k=0;k<n;k++)
		{
			if(a[k]==b[k])q++;
		}
		if(q==n)c[3]=1;
		else c[3]=0;
}

//Metryka kolejowa

void m_kolejowa(double *a, double *b, double *c, int n)
{
		int k=0;
		double s=0,r=0;
		for(k=0;k<n;k++)
		{
			s+=a[k]*a[k];
			r+=b[k]*b[k];
		}
		c[4]=sqrt(s)+sqrt(r);
}

//Metryka przestrzeni X^N

void m_xn(double *a, double *b, double *c, int n)
{
		double licznik=1;
		int k=0;
		for(k=0;k<n;k++)
		{
			if(a[k]!=b[k])break;
			licznik++;
		}
		c[5]=licznik;
}

//Metryka Hamminga

void m_ham(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			if(a[k]!=b[k])licznik++;
		}
		c[6]=licznik;
}

//Metryka Canberra

void m_can(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=(abs(a[k]-b[k]))/(abs(a[k])+abs(b[k]));
		}
		c[7]=licznik;
}

//Metryka roznic kwadratow

void m_ssd(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=(a[k]-b[k])*(a[k]-b[k]);
		}
		c[8]=licznik;
}

//Metryka Mean absolute error

void m_mae(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=abs(a[k]-b[k]);
		}
		c[9]=(licznik/n);
}

//Metryka Cosine similarity

void m_cos(double *a, double *b, double *c, int n)
{
		double licznik1=0,licznik2=0,licznik3=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik1+=a[k]*b[k];
		}
		for(k=0;k<n;k++)
		{
			licznik2+=a[k]*a[k];
		}
		for(k=0;k<n;k++)
		{
			licznik3+=b[k]*b[k];
		}

		c[10]=1-(licznik1/(licznik2*licznik3));
}

//Metryka Bray-Curtis
void m_bc(double *a, double *b, double *c, int n)
{
		double licznik1=0,licznik2=0,licznik3=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik1+=abs(a[k]-b[k]);
		}
		for(k=0;k<n;k++)
		{
			licznik2+=abs(a[k]);
		}
		for(k=0;k<n;k++)
		{
			licznik3+=abs(b[k]);
		}

		c[11]=1-(licznik1/(licznik2+licznik3));
}

void hello_message()
{
	printf("-----------------------------------------\n");
	printf("           KALKULATOR METRYK\n");
	printf("-----------------------------------------\n");
}

