#include "listeArbres.h"


ListeArbres liste_creer(void)
{
	return NULL;
}


bool liste_estVide(ListeArbres l)
{
	return (l==NULL);
}


ListeArbres liste_insererTriArbre(ListeArbres l, Arbre a)
{
	/* Si la liste est vide */
	if(liste_estVide(l))
	{
		l=(ListeArbres)malloc(sizeof(struct element));
		l->arbre=a;
		l->suivant=NULL;
		return l;
	}
	
	/* Si le prochain element a une frequence superieure */
	if(a->freq <= l->arbre->freq)
	{
		ListeArbres new = (ListeArbres)malloc(sizeof(struct element));
		new->arbre=a;
		new->suivant=l;		
		return new;
	}
	
	/* Si fin de liste */
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


Arbre liste_tete(ListeArbres l)
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


ListeArbres liste_construitListeArbres(int freq[256])
{
    int i;
    ListeArbres liste = liste_creer();
    
    for (i=0; i<256; i++)
    {
        if (freq[i] != 0)
        {
            liste = liste_insererTriArbre(liste, arbre_creerFeuille(i, freq[i]));
        }
    }
    return liste;
}


Arbre liste_construitArbre(ListeArbres l)
{
	Arbre result;
	
	if(l->suivant==NULL) return l->arbre;
	
	result = arbre_enrac(l->arbre, l->suivant->arbre);
	
	l=liste_supprimerTete(l);
	l=liste_supprimerTete(l);
	
	l=liste_insererTriArbre(l, result);
	
	return liste_construitArbre(l);
}
