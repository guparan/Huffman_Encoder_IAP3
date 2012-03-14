#include "listeTrieeArbres.h"


ListeTrieeArbres creerListe(void)
{
	return NULL;
}


ListeTrieeArbres insererArbreListe(ListeTrieeArbres l, Arbre a)
{
	/*
	 * if(a->freq < l->suivant->arbre->freq)
	 * ...
	 */
	if(a->freq > l->arbre->freq)
	{
		if(l->suivant==NULL)
		{
			ListeTrieeArbres new = (ListeTrieeArbres)malloc(sizeof(struct element));
			new->arbre=a;
			new->suivant=NULL;
			l->suivant=new;
		}
		else
		{
			l->suivant = insererArbreListe(l->suivant, a);
		}
		return l;
	}
	
	ListeTrieeArbres new = (ListeTrieeArbres)malloc(sizeof(struct element));
	new->arbre=a;
	new->suivant=l;
	
	return new;
}


Arbre teteListe(ListeTrieeArbres l)
{
    return l->arbre;
}


ListeTrieeArbres supprimerTeteListe(ListeTrieeArbres l)
{
    ListeTrieeArbres tmp = l;
    l = l->suivant;
    free(tmp);
    return l;
}