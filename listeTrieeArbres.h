#ifndef LISTETRIEEARBRES_H
#define LISTETRIEEARBRES_H


typedef struct element {
	Arbre arbre;
	struct element* suivant;
} *ListeTrieeArbres;

/****************************************************/

ListeTrieeArbres creerListe(void);
ListeTrieeArbres insererArbreListe(ListeTrieeArbres, Arbre);
Arbre teteListe(ListeTrieeArbres);
ListeTrieeArbres supprimerTeteListe(ListeTrieeArbres);


#endif
