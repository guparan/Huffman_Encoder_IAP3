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


float tauxCompression(FILE* init, FILE* comp)
{
    return (tailleFichier(comp)/tailleFichier(init));
}


FILE* compresse(FILE* input, char* nomFichierComp)
{
    FILE* output = fopen(nomFichierComp, "w+");
    int i = 0, freq[256] = {0};
    analyseFichier(input, freq);
    Arbre huffman = liste_construitArbre(liste_construitListeArbres(freq));
    char** codage = encodage_preEncode(huffman, NULL, NULL, NULL);
    
    while (codage[i] != NULL)   /* écriture du codage au début du nouveau fichier; nécessaire pour la décompression*/
    {
        if (strcmp(codage[i], ""))
        {
            fprintf(output, "%d %s\n", i, codage[i]);
        }
        i++;
    }
    fputs("\n", output);    /* On saute une ligne pour passer au contenu du fichier */
    
    /* Ecriture du contenu du fichier après encodage */
    
    
    return output;
}