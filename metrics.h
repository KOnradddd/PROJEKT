#ifndef ARRAY_H
#define ARRAY_H

int max(int a,int b);
int min(int a,int b);
void m_euklidesowa(double *a, double *b, double *c, int n);
void m_miejska(double *a, double *b, double *c, int n);
void m_dyskretna(double *a, double *b, double *c, int n);
void m_kolejowa(double *a, double *b, double *c, int n);
void m_xn(double *a, double *b, double *c, int n);
void m_ham(double *a, double *b, double *c, int n);
void m_can(double *a, double *b, double *c, int n);
void m_ssd(double *a, double *b, double *c, int n);
void m_mae(double *a, double *b, double *c, int n);
void m_cos(double *a, double *b, double *c, int n);
void m_bc(double *a, double *b, double *c, int n);
void soersen(double *a, double *b, double *c, int n);
void gower(double *a, double *b, double *c, int n);
void soergel(double *a, double *b, double *c, int n);
void kulcz(double *a, double *b, double *c, int n);
void lorentz(double *a, double *b, double *c, int n);
void inter(double *a, double *b, double *c, int n);
void noninter(double *a, double *b, double *c, int n);
void wave(double *a, double *b, double *c, int n);
void motyka(double *a, double *b, double *c, int n);
void ruzicka(double *a, double *b, double *c, int n);
void tani(double *a, double *b, double *c, int n);
void dice(double *a, double *b, double *c, int n);
void bhatta(double *a, double *b, double *c, int n);
void hell(double *a, double *b, double *c, int n);
void matu(double *a, double *b, double *c, int n);
void se(double *a, double *b, double *c, int n);
void sc(double *a, double *b, double *c, int n);
void schi(double *a, double *b, double *c, int n);
void ps(double *a, double *b, double *c, int n);
void dive(double *a, double *b, double *c, int n);
void clark(double *a, double *b, double *c, int n);
void adsi(double *a, double *b, double *c, int n);
void kl(double *a, double *b, double *c, int n);
void jeffreys(double *a, double *b, double *c, int n);
void kdiv(double *a, double *b, double *c, int n);
int random(int min, int max);

#endif
