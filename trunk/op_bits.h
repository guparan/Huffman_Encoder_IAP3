#ifndef OP_BITS_H
#define OP_BITS_H


#include <stdio.h>


/**
 * \fn int tailleFichier(FILE*);
 * \brief Renvoie la taille du fichier en paramètre (fichier préalablement ouvert)
 * 
 * \param Pointeur sur le fichier à mesurer
 **/
int tailleFichier(FILE*);

void ecritNiemeBit(unsigned char *buff, unsigned char bit, int n);

unsigned char  litNiemeBit(unsigned char *buff, int n);


#endif
