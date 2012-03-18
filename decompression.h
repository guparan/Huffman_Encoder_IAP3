#ifndef compression_compresseur_decompression_h
#define compression_compresseur_decompression_h

#include "encodage.h"

/**
 * \fn void decompression_compresse(FILE*, char*);
 * \brief décompression_compresse le fichier en paramètre
 * 
 * \param nom du fichier à décompression_compresser SANS L'EXTENSION (.huf ou .comp)
 **/
FILE* decompression_decompresse(char*);

#endif
