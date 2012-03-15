#ifndef LISTETRIEEARBRES_H
#define LISTETRIEEARBRES_H

#include "arbre.h"


typedef struct element {
	Arbre arbre;
	struct element* suivant;
} *ListeTrieeArbres;


/**
 * \fn ListeTrieeArbres liste_creer(void);
 * \brief Renvoie NULL
 * 
 **/
ListeTrieeArbres liste_creer(void);


/**
 * \fn ListeTrieeArbres liste_insererArbre(ListeTrieeArbres, Arbre);
 * \brief Renvoie une liste construite à partir de la liste et de l'arbre en paramètres
 * 
 * \param l liste d'arbres triée
 * \param a arbre à insérer
 **/
ListeTrieeArbres liste_insererArbre(ListeTrieeArbres, Arbre);


/**
 * \fn Arbre liste_tete(ListeTrieeArbres);
 * \brief Renvoie l'arbre en tête de la liste en paramètre (fréquence la plus faible de la liste)
 * 
 * \param l liste d'arbres triée
 **/
Arbre liste_tete(ListeTrieeArbres);


/**
 * \fn ListeTrieeArbres liste_supprimerTete(ListeTrieeArbres);
 * \brief Supprime le premier arbre de la liste en paramètre et renvoie la nouvelle liste
 * 
 * \param l liste d'arbres triée
 **/
ListeTrieeArbres liste_supprimerTete(ListeTrieeArbres);


#endif
