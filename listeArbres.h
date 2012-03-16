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


/**
 * \fn bool liste_estVide(ListeArbres);
 * \brief Renvoie true (1) si la liste l est vide et false (0) sinon
 * 
 * \param l liste d'arbres
 **/
bool liste_estVide(ListeArbres);


/**
 * \fn void liste_afficher(ListeArbres);
 * \brief Affiche la liste des caractères associée a leur fréquence d'apparition
 * 
 * \param l liste d'arbres étant des feuilles
 **/
void liste_afficher(ListeArbres);


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



/* construction de l'arbre de huffman à partir d'un tableau de fréquence */
/**
 * \fn ListeArbres liste_construitListeArbres(int freq[256]);
 * \brief Construit une liste d'arbres (contenant chacun une seule feuille) à partir du tableau de fréquences obtenu suite à l'analyse d'un fichier
 * 
 * \param freq tableau des fréquences d'apparition des caractères ASCII
 **/
ListeArbres liste_construitListeArbres(int freq[256]);


/**
 * \fn Arbre liste_construitArbre(int freq[256]);
 * \brief Renvoie l'arbre de Huffman construit à partir du tableau de fréquences en paramètre.
 * 
 * \param l liste d'arbres (contenant chacun une unique feuille) correspondant à la liste des caractères apparaissant dans le fichier analysé
 **/
Arbre liste_construitArbre(ListeArbres);

#endif
