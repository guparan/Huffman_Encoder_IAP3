#ifndef LISTETRIEEARBRES_H
#define LISTETRIEEARBRES_H

#include "arbre.h"


typedef struct element {
	Arbre arbre;
	struct element* suivant;
} *ListeTrieeArbres;


/**
 * \fn ListeTrieeArbres creerListe(void);
 * \brief Renvoie NULL
 * 
 **/
ListeTrieeArbres creerListe(void);


/**
 * \fn ListeTrieeArbres insererArbreListe(ListeTrieeArbres, Arbre);
 * \brief Renvoie une liste construite à partir de la liste et de l'arbre en paramètres
 * 
 * \param l liste d'arbres triée
 * \param a arbre à insérer
 **/
ListeTrieeArbres insererArbreListe(ListeTrieeArbres, Arbre);


/**
 * \fn Arbre teteListe(ListeTrieeArbres);
 * \brief Renvoie l'arbre en tête de la liste en paramètre (fréquence la plus faible de la liste)
 * 
 * \param l liste d'arbres triée
 **/
Arbre teteListe(ListeTrieeArbres);


/**
 * \fn ListeTrieeArbres supprimerTeteListe(ListeTrieeArbres);
 * \brief Supprime le premier arbre de la liste en paramètre et renvoie la nouvelle liste
 * 
 * \param l liste d'arbres triée
 **/
ListeTrieeArbres supprimerTeteListe(ListeTrieeArbres);


#endif
