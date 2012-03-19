#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include <errno.h>
#include "encodage.h"
#include "op_bits.h"

/**
 * \fn void decompression_compresse(FILE*, char*);
 * \brief décompression_compresse le fichier en paramètre
 * 
 * \param nom du fichier à décompression_compresser SANS L'EXTENSION (.huf ou .comp)
 **/
FILE* decompression_decompresse(char*);

#endif
