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
 * \fn int tauxCompression(FILE* av, FILE* ap);
 * \brief Renvoie le taux de compression obtenu
 * 
 * \param Pointeurs sur le fichier initial et le fichier compressé
 **/
float tauxCompression(FILE* init, FILE* comp);


/**
 * \fn void compresse(FILE*, char*);
 * \brief créé un fichier compréssé à partir de celui en paramètre
 * 
 * \param fichier à compresser
 * \param nom du fichier de sortie
 **/
FILE* compresse(FILE*, char*);


#endif
