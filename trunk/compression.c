#include <stdio.h>
#include "compression.h"

int compression_tailleFichier(FILE* fp)
{
    int res = 0;
    fseek(fp, 0, SEEK_END);
    res = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return res;
}


float compression_tauxCompression(FILE* init, FILE* comp, FILE* codage)
{
    return ((compression_tailleFichier(comp)+compression_tailleFichier(codage))/compression_tailleFichier(init));
}


FILE* compression_compresse(FILE* input, char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL; 
    Arbre huffman;
    char** codage;
    char *extensionFichComp = ".comp", *extensionFichCodage = ".huf";
    int i = 0, freq[256] = {0};
    encodage_analyseFichier(input, freq);
    huffman = liste_construitArbre(liste_construitListeArbres(freq));
    codage = encodage_tabCorrespondance(huffman);
    
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
    printf("Taux de compression obtenu: %f", compression_tauxCompression(input, fichierComp, fichierCodage));
    
    return fichierComp;
}
