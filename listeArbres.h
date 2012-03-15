#ifndef ListeArbres_H
#define ListeArbres_H

#include "arbre.h"


typedef struct element {
	Arbre arbre;
	struct element* suivant;
} *ListeArbres;


/**
 * \fn ListeArbres liste_creer(void);
 * \brief Renvoie NULL
 * 
 **/
ListeArbres liste_creer(void);


ListeArbres liste_estVide(ListeArbres);


/**
 * \fn ListeArbres liste_insererTriArbre(ListeArbres, Arbre);
 * \brief Renvoie une liste construite à partir de la liste et de l'arbre en paramètres
 * 
 * \param l liste d'arbres triée
 * \param a arbre à insérer
 **/
ListeArbres liste_insererTriArbre(ListeArbres, Arbre);


/**
 * \fn Arbre liste_tete(ListeArbres);
 * \brief Renvoie l'arbre en tête de la liste en paramètre (fréquence la plus faible de la liste)
 * 
 * \param l liste d'arbres triée
 **/
Arbre liste_tete(ListeArbres);


/**
 * \fn ListeArbres liste_supprimerTete(ListeArbres);
 * \brief Supprime le premier arbre de la liste en paramètre et renvoie la nouvelle liste
 * 
 * \param l liste d'arbres triée
 **/
ListeArbres liste_supprimerTete(ListeArbres);


#endif
