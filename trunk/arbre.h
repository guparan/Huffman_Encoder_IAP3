#ifndef __ARBRE_H_
#define __ARBRE_H_

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

/* 0 : fils gauche, 1 : fils droit */
typedef struct noeud {
	unsigned char* c;
	int freq;
	struct noeud *fg, *fd; /* fils gauche, fils droit */
} *Arbre;

Arbre creerFeuille(unsigned char* c, int freq);
Arbre enrac(Arbre a_gauche, Arbre a_droit); /* freq = freq de a_gauche + freq de a_droit */

/* selecteurs et tests élémentaires */
Arbre fg(Arbre);
Arbre fd(Arbre);
int frequenceRacine(Arbre);
bool estVide(Arbre);
bool estFeuille(Arbre);
unsigned char* carRacine(Arbre);
/* affichage infixe d'un arbre (fg - racine - fd) */
void afficheArbre(Arbre, void(*f)(unsigned char*, int));
void parseArbre(Arbre, FILE*);
void afficheArbreDot(Arbre, char*);
/* construction de l'arbre de huffman à partir d'un tableau de fréquence */
Arbre construitArbre(int freq[256]);

#endif
