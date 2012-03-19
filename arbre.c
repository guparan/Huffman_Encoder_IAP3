#include "arbre.h"

Arbre arbre_creerFeuille(unsigned char c, int freq)
{
	Arbre a = (Arbre)malloc(sizeof(struct noeud));
	a->c=c;
	a->freq=freq;
	a->fg=NULL;
	a->fd=NULL;
	
	return a;
}


Arbre arbre_enrac(Arbre a_gauche, Arbre a_droit)
{
	Arbre a = arbre_creerFeuille('\0', a_gauche->freq + a_droit->freq);
	a->fg=a_gauche;
	a->fd=a_droit;
	
	return a;
}


Arbre arbre_fg(Arbre a)
{
	return a->fg;
}


Arbre arbre_fd(Arbre a)
{
	return a->fd;
}


int arbre_frequenceRacine(Arbre a)
{
	return a->freq;
}


bool arbre_estVide(Arbre a)
{
	return (a==NULL);
}


bool arbre_estFeuille(Arbre a)
{
	return (arbre_estVide(arbre_fd(a)) && arbre_estVide(arbre_fg(a)));
}


unsigned char arbre_carRacine(Arbre a)
{
	return a->c;
}


/* precondition : l'arbre est un ABR */
int arbre_nbFeuilles(Arbre a)
{
	if(arbre_estVide(arbre_fg(a)) && arbre_estVide(arbre_fd(a)))
	{
		return 1;
	}
	else return arbre_nbFeuilles(arbre_fg(a))+arbre_nbFeuilles(arbre_fd(a));
}


void arbre_afficheArbre(Arbre a, void(*f)(unsigned char, int))
{
	if(arbre_estVide(a)) return;
	
	arbre_afficheArbre(arbre_fg(a), f);
	f(arbre_carRacine(a), arbre_frequenceRacine(a));
	arbre_afficheArbre(arbre_fd(a), f);
}


void arbre_afficheArbreDot(Arbre a, char* filename)
{
	FILE* f;
	char* command;
	command=(char*)malloc(2*strlen(filename)*sizeof(char)+34);
	
	if((f=fopen(filename, "w+"))==NULL) 
	{ 
		fprintf(stderr, "Pb ouverture ou creation \n");
		exit(1);
	}
	
	fprintf(f, "graph graphname {\n");
	arbre_parseArbre(a, f);
	fprintf(f, "}\n");
		
	fclose(f);
	sprintf(command, "dot %s -Tpng -Gcharset=latin1 -o %s.png", filename, filename);
	if(system(command)==-1)
	{
		fprintf(stderr, "Erreur fct system");
		exit(-1);
	}
    free(command);
}


void arbre_parseArbre(Arbre a, FILE* file)
{	
	if(arbre_estVide(a)) return;

	if(!arbre_estVide(arbre_fg(a)))
	{
		if(arbre_carRacine(a)=='\0' && arbre_carRacine(arbre_fg(a))=='\0')
		{
			fprintf(file, "\"%d (%u)\" -- \"%d (%u)\";\n", arbre_frequenceRacine(a), (unsigned int)a, arbre_frequenceRacine(arbre_fg(a)), (unsigned int)arbre_fg(a));
		}
		else if(arbre_carRacine(a)=='\0' && arbre_carRacine(arbre_fg(a))!='\0')
		{
			fprintf(file, "\"%d (%u)\" -- \"%d : %d\";\n", arbre_frequenceRacine(a), (unsigned int)a, arbre_carRacine(arbre_fg(a)), arbre_frequenceRacine(arbre_fg(a)));
		}
		else if(arbre_carRacine(a)!='\0' && arbre_carRacine(arbre_fg(a))=='\0')
		{
			fprintf(file, "\"%d : %d\" -- \"%d (%u)\";\n", arbre_carRacine(a), arbre_frequenceRacine(a), arbre_frequenceRacine(arbre_fg(a)), (unsigned int)arbre_fg(a));
		}
		else if(arbre_carRacine(a)!='\0' && arbre_carRacine(arbre_fg(a))!='\0')
		{
			fprintf(file, "\"%d : %d\" -- \"%d : %d\";\n", arbre_carRacine(a), arbre_frequenceRacine(a), arbre_carRacine(arbre_fg(a)), arbre_frequenceRacine(arbre_fg(a)));
		}
		arbre_parseArbre(arbre_fg(a), file);
	}
	
	if(!arbre_estVide(arbre_fd(a)))
	{
		if(arbre_carRacine(a)=='\0' && arbre_carRacine(arbre_fd(a))=='\0')
		{
			fprintf(file, "\"%d (%u)\" -- \"%d (%u)\";\n", arbre_frequenceRacine(a), (unsigned int)a, arbre_frequenceRacine(arbre_fd(a)), (unsigned int)arbre_fd(a));
		}
		else if(arbre_carRacine(a)=='\0' && arbre_carRacine(arbre_fd(a))!='\0')
		{
			fprintf(file, "\"%d (%u)\" -- \"%d : %d\";\n", arbre_frequenceRacine(a), (unsigned int)a, arbre_carRacine(arbre_fd(a)), arbre_frequenceRacine(arbre_fd(a)));
		}
		else if(arbre_carRacine(a)!='\0' && arbre_carRacine(arbre_fd(a))=='\0')
		{
			fprintf(file, "\"%d : %d\" -- \"%d (%u)\";\n", arbre_carRacine(a), arbre_frequenceRacine(a), arbre_frequenceRacine(arbre_fd(a)), (unsigned int)arbre_fd(a));
		}
		else if(arbre_carRacine(a)!='\0' && arbre_carRacine(arbre_fd(a))!='\0')
		{
			fprintf(file, "\"%d : %d\" -- \"%d : %d\";\n", arbre_carRacine(a), arbre_frequenceRacine(a), arbre_carRacine(arbre_fd(a)), arbre_frequenceRacine(arbre_fd(a)));
		}
		arbre_parseArbre(arbre_fd(a), file);
	}
}
