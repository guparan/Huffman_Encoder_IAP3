#ifndef OP_BITS_H
#define OP_BITS_H
	
#include <stdio.h>
#include <limits.h>

/**
 * \fn int tailleFichier(FILE*);
 * \brief Renvoie la taille du fichier en paramètre (fichier préalablement ouvert)
 * 
 * \param Pointeur sur le fichier à mesurer
 **/
int tailleFichier(FILE*);


/**
 * \fn void ecritNiemeBit(unsigned char *buff, unsigned char bit, int n);

 * \brief 
 * 
 * \param buff
 * \param bit
 * \param n 
 **/
void ecritNiemeBit(unsigned char *buff, unsigned char bit, int n);


/**
 * \fn unsigned char litNiemeBit(unsigned char *buff, int n);
 * \brief 
 * 
 * \param buff
 * \param n
 **/
unsigned char litNiemeBit(unsigned char *buff, int n);


/**
 * \fn void afficher_binaire(unsigned char a);
 * \brief 
 * 
 * \param 
 **/
void afficher_binaire(unsigned char a);

#endif
