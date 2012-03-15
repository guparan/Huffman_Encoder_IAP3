#ifndef __ENCODAGE_H_
#define __ENCODAGE_H_

#include <stdio.h>
#include "arbre.h"
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


/**
 * \fn char* encode(Arbre a, char c);
 * \brief Produit la séquence de bits du code de Huffman (sous forme d'une chaîne de caractères) à partir d'un arbre de Huffman et d'un caractère
 * 
 * \param a arbre de Huffman à parcourir pour encoder
 * \param c caractère à coder
 **/
char* encode(Arbre a, char c);


/**
 * \fn char* decode(Arbre a, char c);
 * \brief Renvoie le caractère correspondant à la séquence de bits du code appliquée à l'arbre a
 * 
 * \param a arbre de Huffman à parcourir pour décoder
 * \param code séquence de bits à décoder
 **/
char decode(Arbre a, char* code);


#endif
