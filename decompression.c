#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decompression.h"

FILE* decompresse(char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL, *fichierDecomp = NULL;
    char *extensionFichComp = ".comp", *extensionFichCodage = ".tabfreq", *buffer = NULL;
    int caractereActuel = 0, i = 0, j = 0, freq[256];
    
    fichierCodage = fopen(strcat(nomFichier, extensionFichCodage), "r");
    
    /* Création de la table des fréquences à utiliser (obtenue par lecture de l'entête du fichier input)*/
        
    while (caractereActuel != EOF)
    {
        caractereActuel = fgetc(fichierComp);   /* on lit l'indice */
        i = caractereActuel;    /* on l'affecte à i */
        caractereActuel = fgetc(fichierComp);   /* on passe le caractère " " (espace) qui sépare l'indice du code */
        caractereActuel = fgetc(fichierComp);   /* lecture du premier chiffre de la fréquence associée */
        
        while (caractereActuel != '\n')     /* on lit le code à placer dans freq[i] */
        {
            j++;    /* nombre de char dans le buffer */
            realloc(buffer, j*sizeof(char));
            buffer[j-1] = caractereActuel;      /* on remplit le buffer avec le chiffre (char) lu */
            caractereActuel = fgetc(fichierComp);   /* on passe au caractère suivant */
        }
        
        freq[i] = atoi(buffer); /* atoi : conversion string to int */
        j = 0;      /* on réinitialise j */
        free(buffer);   /* on réinitialise le buffer */
    }
    
    /* Création de l'arbre de Huffman */
    Arbre huffman = liste_construitArbre(liste_construitListeArbres(freq));
    
    /* Décompression du fichier */
    fichierComp = fopen(strcat(nomFichier, extensionFichComp), "r");
    fichierDecomp = fopen(nomFichier, "w+");
    
    
    return fichierDecomp;
}
