#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 13

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int min(int a,int b)
{
    if(a>b)return b;
    else return a;
}

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
//Sorersen

void soersen(double *a, double *b, double *c, int n)
{
		double licznik=0;
		double mianownik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=abs(a[k]-b[k]);
			mianownik+=(a[k]+b[k]);
		}
		c[12]=(licznik/mianownik);
}

//Gower

void gower(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=abs(a[k]-b[k]);
		}
		c[13]=(licznik/n);
}

//Soergel

void soergel(double *a, double *b, double *c, int n)
{
		double licznik=0;
		double mianownik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=abs(a[k]-b[k]);
			mianownik+=max(a[k],b[k]);
		}
		c[14]=(licznik/mianownik);
}

//Kulczynski

void kulcz(double *a, double *b, double *c, int n)
{
		double licznik=0;
		double mianownik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=abs(a[k]-b[k]);
			mianownik+=min(a[k],b[k]);
		}
		c[15]=(licznik/mianownik);
}

//Lorentzian

void lorentz(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=log(abs(a[k]-b[k])+1);
		}
		c[16]=(licznik);
}

//Intersection

void inter(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=min(a[k],b[k]);
		}
		c[17]=(licznik);
}

//Non-intersection

void noninter(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=abs(a[k]-b[k]);
		}
		c[18]=(licznik/2);
}

//Wave Edges

void wave(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=(abs(a[k]-b[k])/max(a[k],b[k]));
		}
		c[19]=(licznik);
}

//Motyka

void motyka(double *a, double *b, double *c, int n)
{
		double licznik=0;
		double mianownik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=max(a[k],b[k]);
			mianownik+=(a[k]+b[k]);
		}
		c[20]=(licznik/mianownik);
}

//Ruzicka

void ruzicka(double *a, double *b, double *c, int n)
{
		double licznik=0;
		double mianownik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=min(a[k],b[k]);
			mianownik+=max(a[k],b[k]);
		}
		c[21]=(licznik/mianownik);
}

//Tanimoto

void tani(double *a, double *b, double *c, int n)
{
		double licznik=0;
		double mianownik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=(max(a[k],b[k])-min(a[k],b[k]));
			mianownik+=max(a[k],b[k]);
		}
		c[22]=(licznik/mianownik);
}

//Dice
void dice(double *a, double *b, double *c, int n)
{
		double licznik=0;
		double mianownik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=((a[k]-b[k])*(a[k]-b[k]));
			mianownik+=(a[k]*a[k]);
			mianownik+=(b[k]*b[k]);
		}
		c[23]=(licznik/mianownik);
}

//Bhattacharyya

void bhatta(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=sqrt(a[k]*b[k]);
		}
		c[24]=log(licznik)*(-1);
}

//Hellinger

void hell(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=sqrt(a[k]*b[k]);
		}
		c[25]=2*sqrt(1-licznik);
}

//Matusita

void matu(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=sqrt(a[k]*b[k]);
		}
		c[26]=sqrt(2-2*licznik);
}

//Squared euclidean

void se(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=((a[k])-(b[k]))*((a[k])-(b[k]));
		}
		c[27]=licznik;
}

//Squared chord
void sc(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=(sqrt(a[k])-sqrt(b[k]))*(sqrt(a[k])-sqrt(b[k]));
		}
		c[28]=licznik;
}

//Squared chi
void schi(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=((a[k]-b[k])*(a[k]-b[k])/(a[k]+b[k]));
		}
		c[29]=licznik;
}

//Probabilistic symmetric

void ps(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=((a[k]-b[k])*(a[k]-b[k])/(a[k]+b[k]));
		}
		c[30]=2*licznik;
}

//Divergence

void dive(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int k=0;
		for(k=0;k<n;k++)
		{
			licznik+=((a[k]-b[k])*(a[k]-b[k])/((a[k]+b[k]))*(a[k]+b[k]));
		}
		c[31]=2*licznik;
}

//Clark

void clark(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			licznik+=((abs(a[i]-b[i])/(a[i]+b[i]))*(abs(a[i]-b[i])/(a[i]+b[i])));
		}
		c[32]=licznik;
}

//Additivesymmetric

void adsi(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			licznik+=(a[i]-b[i])*(a[i]-b[i])*(a[i]+b[i])/(a[i]*b[i]);
		}
		c[33]=licznik;
}

//Kullback-Leibler


void kl(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			licznik+=a[i]*log(a[i]/b[i]);
		}
		c[34]=licznik;
}

//Jeffreys


void jeffreys(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			licznik+=(a[i]-b[i])*log(a[i]/b[i]);
		}
		c[35]=licznik;
}

//K divergence


void kdiv(double *a, double *b, double *c, int n)
{
		double licznik=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			licznik+=a[i]*log(2*a[i]/(a[i]+b[i]));
		}
		c[36]=licznik;
}

int random(int min, int max)
{
    int tmp;
    if (max>=min)
        max-= min;
    else
    {
        tmp= min - max;
        min= max;
        max= tmp;
    }
    return max ? (rand() % max + min) : min;
}
void hello_message()
{
	printf("-----------------------------------------\n");
	printf("           KALKULATOR METRYK\n");
	printf("-----------------------------------------\n");
}

