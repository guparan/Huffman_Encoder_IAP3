#ifndef __ENCODAGE_H_#define __ENCODAGE_H_
#include <stdio.h>/**
 * \fn void analyseFichier(FILE *fp, int freq[256])
 * \brief Remplit le tableau freq avec le nombre d'occurences de chaque caractère du fichier pointé par fp
 * 
 * \param fp pointeur sur un fichier déjà ouvert avant d'appeler la fonction
 * \param freq pointeur sur un tableau de 256 entiers initialisés à 0
 **/void analyseFichier(FILE *fp, int freq[256]);


/* Pour le codage lors de la lecture de l'arbre:
0 : fils gauche, 1 : fils droit */


#endif