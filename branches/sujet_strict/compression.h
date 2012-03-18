#ifndef Compresseur_compression_h
#define Compresseur_compression_h

#include "encodage.h"

/**
 * \fn int tailleFichier(FILE*);
 * \brief Renvoie la taille du fichier en paramètre (fichier préalablement ouvert)
 * 
 * \param Pointeur sur le fichier à mesurer
 **/
int tailleFichier(FILE*);


/**
 * \fn int tauxCompression(FILE* init, FILE* comp, FILE* codage);
 * \brief Renvoie le taux de compression obtenu
 * 
 * \param Pointeur sur le fichier initial
 * \param Pointeur sur le fichier compressé
 * \param Pointeur sur le fichier contenant le codage utilisé
 **/
float tauxCompression(FILE* init, FILE* comp, FILE* codage);


/**
 * \fn void compresse(FILE*, char*);
 * \brief créé un fichier compréssé à partir de celui en paramètre
 * 
 * \param fichier à compresser
 * \param nom du fichier
 **/
FILE* compresse(FILE*, char*);


#endif
