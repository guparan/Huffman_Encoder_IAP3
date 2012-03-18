#ifndef __ENCODAGE_H_
#define __ENCODAGE_H_

#include <stdio.h>
#include <string.h>
#include "listeArbres.h"


/**
 * \fn void analyseFichier(FILE *fp, int freq[256])
 * \brief Remplit le tableau freq avec le nombre d'occurences de chaque caractère du fichier pointé par fp
 * 
 * \param fp pointeur sur un fichier déjà ouvert avant d'appeler la fonction
 * \param freq pointeur sur un tableau de 256 entiers initialisés à 0
 **/
void analyseFichier(FILE *fp, int freq[256]);


/* Pour le codage lors de la lecture de l'arbre:
 0 : fils gauche, 1 : fils droit */


char** encodage_construitTabCorres(Arbre a, int nbFeuilles, char* construct, char** binaire, int* nbFeuillesTraitees);


char** encodage_tabCorrespondance(Arbre a);


/**
 * \fn char* encode(char c, char** tabCorrespondance);
 * \brief Retourne la séquence de bits du code de Huffman correspondant au caractère en paramètre
 * 
 * \param caractère à coder
 * \param tableau des correspondances ASCII / codage à utiliser
 **/
char* encode(char**, char);


/**
 * \fn char* decode(Arbre a, char c);
 * \brief Renvoie le caractère correspondant à la séquence de bits du code appliquée à l'arbre a
 * 
 * \param a arbre de Huffman à parcourir pour décoder
 * \param code séquence de bits à décoder
 **/
char decode_arbre(Arbre a, char* code);


char decode(char**, char*);


#endif
