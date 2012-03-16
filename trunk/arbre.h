#ifndef __ARBRE_H_
#define __ARBRE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h"


typedef struct noeud {
	unsigned char c;
	int freq;
	struct noeud *fg, *fd; /* fils gauche, fils droit */
} *Arbre;


/**
 * \fn Arbre arbre_creerFeuille(unsigned char c, int freq);
 * \brief Cree un arbre contenant une unique feuille
 * 
 * \param c caractère à assigner à la feuille
 * \param freq fréquence associée au caractère c
 **/
Arbre arbre_creerFeuille(unsigned char c, int freq);


/**
 * \fn Arbre arbre_enrac(Arbre a_gauche, Arbre a_droit);
 * \brief Renvoie un arbre ayant pour fils gauche et droit les deux arbres en paramètre et pour fréquence la somme des fréquences des arbres en paramètre.
 * 
 * \param a_gauche arbre à placer en tant que fils gauche
 * \param a_droit arbre à placer en tant que fils droit
 **/
Arbre arbre_enrac(Arbre a_gauche, Arbre a_droit); /* freq = freq de a_gauche + freq de a_droit */




/* selecteurs et tests élémentaires */

/**
 * \fn Arbre arbre_fg(Arbre);
 * \brief Retourne le fils gauche de l'arbre en paramère
 * 
 * \param arbre 
 **/
Arbre arbre_fg(Arbre);


/**
 * \fn Arbre arbre_fd(Arbre);
 * \brief Retourne le fils droit de l'arbre en paramère
 * 
 * \param arbre 
 **/
Arbre arbre_fd(Arbre);


/**
 * \fn int arbre_frequenceRacine(Arbre);
 * \brief Retourne la fréquence de la racine de l'arbre en paramètre
 * 
 * \param arbre
 **/
int arbre_frequenceRacine(Arbre);


/**
 * \fn bool arbre_estVide(Arbre);
 * \brief Teste si un arbre est vide: renvoie true (1) si vide et false (0) sinon
 * 
 * \param arbre
 **/
bool arbre_estVide(Arbre);


/**
 * \fn bool arbre_estFeuille(Arbre);
 * \brief Renvoie true (1) si l'arbre en paramètre est une feuille et false (0) sinon
 * 
 * \param arbre
 **/
bool arbre_estFeuille(Arbre);


/**
 * \fn unsigned char arbre_carRacine(Arbre);
 * \brief Renvoie le caractère de la racine de l'arbre en paramètre. Si ce n'est pas une feuille, la fonction renvoie le caractère nul (\0).
 * 
 * \param arbre
 **/
unsigned char arbre_carRacine(Arbre);


int arbre_nbFeuilles(Arbre);



/* affichage infixe d'un arbre (fg - racine - fd) */

/**
 * \fn void arbre_afficheArbre(Arbre, void(*f)(unsigned char, int));
 * \brief affiche l'arbre en paramètre en utilisant la fonction f donnée en deuxième paramètre
 * 
 * \param arbre à afficher
 * \param f fonction d'affichage
 **/
void arbre_afficheArbre(Arbre, void(*f)(unsigned char, int));


/**
 * \fn void arbre_parseArbre(Arbre, FILE*);
 * \brief Ecrit dans le fichier en paramètre le code décrivant les arêtes pour l'affichage DOT de l'arbre
 * 
 * \param arbre à afficher
 * \param fichier pointeur sur le fichier dans lequel il faut écrire
 **/
void arbre_parseArbre(Arbre, FILE*);


/**
 * \fn void arbre_afficheArbreDot(Arbre, char*);
 * \brief Ecrit dans le fichier en paramètre le code permettant de générer l'affichage de l'arbre en DOT
 * 
 * \param arbre à afficher
 * \param fichier pointeur sur le fichier dans lequel il faut écrire
 **/
void arbre_afficheArbreDot(Arbre, char*);



#endif
