#include <stdio.h>
#include "compression.h"

int tailleFichier(FILE* fp)
{
    int res = 0;
    fseek(fp, 0, SEEK_END);
    res = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return res;
}


float tauxCompression(FILE* init, FILE* comp, FILE* codage)
{
    return ((tailleFichier(comp)+tailleFichier(codage))/tailleFichier(init));
}


FILE* compresse(FILE* input, char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL; 
    char *extensionFichComp = ".comp", *extensionFichCodage = ".huf";
    int i = 0, freq[256] = {0};
    analyseFichier(input, freq);
    Arbre huffman = liste_construitArbre(liste_construitListeArbres(freq));
    char** codage = encodage_tabCorrespondance(huffman);
    
    /* Ecriture du codage dans le fichier dédié; nécessaire pour la décompression */
    fichierCodage = fopen(strcat(nomFichier, extensionFichCodage), "w+");
    while (codage[i] != NULL)
    {
        if (strcmp(codage[i], ""))
        {
            fprintf(fichierCodage, "%d %s\n", i, codage[i]);
        }
        i++;
    }
    
    /* Ecriture du contenu du fichier compressé */
    fichierComp = fopen(strcat(nomFichier, extensionFichComp), "w+");
    /* à faire ... */
    
    /* Affichage du taux de compression */
    printf("Taux de compression obtenu: %f", tauxCompression(input, fichierComp, fichierCodage));
    
    return fichierComp;
}