#include "arbre.h"

Arbre creerFeuille(unsigned char c, int freq)
{
	Arbre a = (Arbre)malloc(sizeof(struct noeud));
	a->c=c;
	a->freq=freq;
	a->fg=NULL;
	a->fd=NULL;
	
	return a;
}


Arbre enrac(Arbre a_gauche, Arbre a_droit)
{
	Arbre a = creerFeuille(' ', a_gauche->freq+a_droit->freq);
	a->fg=a_gauche;
	a->fd=a_droit;
	
	return a;
}


Arbre fg(Arbre a)
{
	return a->fg;
}


Arbre fd(Arbre a)
{
	return a->fd;
}


int frequenceRacine(Arbre a)
{
	return a->freq;
}


bool estVide(Arbre a)
{
	return (a==NULL);
}


bool estFeuille(Arbre a)
{
	return (estVide(fd(a)) && estVide(fg(a)));
}


unsigned char carRacine(Arbre a)
{
	return a->c;
}


void afficheArbre(Arbre a, void(*f)(char, int))
{
	if(estVide(a)) return;
	
	afficheArbre(fg(a), f);
	f(carRacine(a), frequenceRacine(a));
	afficheArbre(fd(a), f);
}
