#ifndef Compresseur_decompression_h
#define Compresseur_decompression_h

#include "encodage.h"

/**
 * \fn void decompresse(FILE*, char*);
 * \brief décompresse le fichier en paramètre
 * 
 * \param nom du fichier à décompresser SANS L'EXTENSION (.huf ou .comp)
 **/
FILE* decompresse(char*);

#endif
