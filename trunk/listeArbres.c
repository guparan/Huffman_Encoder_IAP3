#include "listeArbres.h"


ListeArbres liste_creer(void)
{
	return NULL;
}


ListeArbres liste_insererTriArbre(ListeArbres l, Arbre a)
{	
	if(a->freq <= l->arbre->freq)
	{
		ListeArbres new = (ListeArbres)malloc(sizeof(struct element));
		new->arbre=a;
		new->suivant=l;		
		return new;
	}
	
	if(l->suivant==NULL)
	{
		ListeArbres new = (ListeArbres)malloc(sizeof(struct element));
		new->arbre=a;
		new->suivant=NULL;
		l->suivant=new;
	}
	else
	{
		l->suivant = liste_insererTriArbre(l->suivant, a);
	}
	return l;
}


Arbre tete(ListeArbres l)
{
    return l->arbre;
}


ListeArbres liste_supprimerTete(ListeArbres l)
{
    ListeArbres tmp = l;
    l = l->suivant;
    free(tmp);
    return l;
}
