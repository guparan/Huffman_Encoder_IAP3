#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* decompresse(char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL, *fichierDecomp = NULL;
    char *extensionFichComp = ".comp", *extensionFichCodage = ".huf", *buffer = NULL;
    int caractereActuel = 0, i = 0, j = 0;
    char** tabCorrespondance = malloc(256*sizeof(char*));
    
    fichierCodage = fopen(strcat(nomFichier, extensionFichCodage), "r");
    
    /* Création de la table d'association ASCII / codage à utiliser (obtenue par lecture de l'entête du fichier input)*/
    
    /* LA FONCTION DECODE PERD SON INTERET ! */
    
    while (caractereActuel != EOF)
    {
        caractereActuel = fgetc(fichierComp);   /* on lit l'indice */
        i = caractereActuel;    /* on l'affecte à i */
        caractereActuel = fgetc(fichierComp);   /* on passe le caractère " " (espace) qui sépare l'indice du code */
        
        while (caractereActuel != '\n')     /* on lit le code à placer dans tabCorrespondance[i] */
        {
            j++;    /* nombre de char dans le buffer */
            realloc(buffer, j*sizeof(char));
            buffer[j-1] = caractereActuel;      /* on remplit le buffer avec le code (suite de 0 et 1) */
            caractereActuel = fgetc(fichierComp);   /* on passe au caractère suivant */
        }
        
        tabCorrespondance[i] = buffer;
        j = 0;      /* on réinitialise j */
        free(buffer);   /* on réinitialise le buffer */
    }
    
    /* Décompression du fichier */
    fichierComp = fopen(strcat(nomFichier, extensionFichComp), "r");
    fichierDecomp = fopen(nomFichier, "w+");
    
    
    return fichierDecomp;
}
