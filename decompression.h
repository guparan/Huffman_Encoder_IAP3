#ifndef compression_compresseur_decompression_h
#define compression_compresseur_decompression_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "compression.h"
#include "op_bits.c"

/**
 * \fn void decompression_compresse(FILE*, char*);
 * \brief décompression_compresse le fichier en paramètre
 * 
 * \param nom du fichier à décompression_compresser SANS L'EXTENSION (.huf ou .comp)
 **/
FILE* decompression_decompresse(char*);

#endif
