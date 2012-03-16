//
//  compression.h
//  Compresseur
//
//  Created by Lucas Saurel on 16/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Compresseur_compression_h
#define Compresseur_compression_h


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


#endif
