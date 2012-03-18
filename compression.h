#ifndef compression_compresseur_compression_h
#define compression_compresseur_compression_h

#include <stdio.h>
#include <errno.h>
#include "encodage.h"
#include "op_bits.c"

/**
 * \fn int compression_tailleFichier(FILE*);
 * \brief Renvoie la taille du fichier en paramètre (fichier préalablement ouvert)
 * 
 * \param Pointeur sur le fichier à mesurer
 **/
int compression_tailleFichier(FILE*);


/**
 * \fn int compression_tauxCompression(FILE* init, FILE* comp, FILE* codage);
 * \brief Renvoie le taux de compression obtenu
 * 
 * \param Pointeur sur le fichier initial
 * \param Pointeur sur le fichier compressé
 * \param Pointeur sur le fichier contenant le codage utilisé
 **/
float compression_tauxCompression(FILE* init, FILE* comp, FILE* codage);


/**
 * \fn void compression_compresse(FILE*, char*);
 * \brief créé un fichier compréssé à partir de celui en paramètre
 * 
 * \param fichier à compression_compresser
 * \param nom du fichier
 **/
FILE* compression_compresse(char*);


#endif
