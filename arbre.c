#include "arbre.h"

Arbre creerFeuille(unsigned char* c, int freq)
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
	Arbre a = creerFeuille(NULL, a_gauche->freq + a_droit->freq);
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


unsigned char* carRacine(Arbre a)
{
	return a->c;
}


void afficheArbre(Arbre a, void(*f)(char*, int))
{
	if(estVide(a)) return;
	
	afficheArbre(fg(a), f);
	f(carRacine(a), frequenceRacine(a));
	afficheArbre(fd(a), f);
}


void afficheArbreDot(Arbre a, char* filename)
{
	FILE* f;
	
	if((f=fopen(filename, "w+"))==NULL) 
	{ 
		fprintf(stderr, "Pb ouverture ou creation \n");
		exit(1);
	}
	
	fprintf(f, "graph graphname {\n");
	parseArbre(a, f);
	fprintf(f, "}\n");
		
	fclose(f);
}


void parseArbre(Arbre a, FILE* file)
{	
	if(estVide(a)) return;

	if(!estVide(fg(a)))
	{
		fprintf(file, "%c.%d -- %c.%d;\n", carRacine(a), frequenceRacine(a), carRacine(fg(a)), frequenceRacine(fg(a)));
		parseArbre(fg(a), file);
	}
	
	if(!estVide(fd(a)))
	{
		fprintf(file, "%c.%d -- %c.%d;\n", carRacine(a), frequenceRacine(a), carRacine(fd(a)), frequenceRacine(fd(a)));
		parseArbre(fd(a), file);
	}
}


Arbre construitArbre(int freq[256])
{
	
}
