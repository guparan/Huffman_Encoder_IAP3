#include "listeTrieeArbres.h"


ListeTrieeArbres liste_creer(void)
{
	return NULL;
}


ListeTrieeArbres liste_insererArbre(ListeTrieeArbres l, Arbre a)
{	
	if(a->freq <= l->arbre->freq)
	{
		ListeTrieeArbres new = (ListeTrieeArbres)malloc(sizeof(struct element));
		new->arbre=a;
		new->suivant=l;		
		return new;
	}
	
	if(l->suivant==NULL)
	{
		ListeTrieeArbres new = (ListeTrieeArbres)malloc(sizeof(struct element));
		new->arbre=a;
		new->suivant=NULL;
		l->suivant=new;
	}
	else
	{
		l->suivant = liste_insererArbre(l->suivant, a);
	}
	return l;
}


Arbre tete(ListeTrieeArbres l)
{
    return l->arbre;
}


ListeTrieeArbres liste_supprimerTete(ListeTrieeArbres l)
{
    ListeTrieeArbres tmp = l;
    l = l->suivant;
    free(tmp);
    return l;
}
