#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <errno.h>
#include "arbre.h"
#include "encodage.h"
#include "op_bits.h"



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
void compression_compresse(char*);


#endif
