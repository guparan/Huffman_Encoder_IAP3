/**
 * \file main.c
 * \author Guillaume PARAN & Lucas SAUREL
 * \brief Menu et fonction main
 **/

/**
 * \file arbre.c
 * \file listeArbres.c
 * \file encodage.c
 * \file compression.c
 * \file decompression.c
 * \file op_bits.c
 * \file testArbre.c
 **/

#include "compression.h"
#include "decompression.h"

void menuCompresseur()
{
    char choix [100], *nomFichier = NULL;
    int input = 0;
    
    while (input != 9)
    {
        printf(" === Progrmma de compression/décompression de fichiers === \n1. Compresser un fichier\n2. Décompresser un fichier\n\n9. Quitter\n\n");
        scanf("%s", &choix);
        sscanf(choix, "%d", &input);
        
        switch(input)
        {
            case 1:
                printf("Entrez le nom du fichier à compresser (extension comprise):\n");
                scanf("%s", nomFichier);
                compression_compresse(nomFichier);
                break;
            case 2:
                printf("Entrez le nom du fichier à décompresser (extension NON comprise):\n");
                scanf("%s", nomFichier);
                decompression_decompresse(nomFichier);
                break;
            case 9:
                system("clear");
                printf("A bientôt\n");
                break;
            default:
                system("clear");
                printf("Ce choix n'existe pas\n\n");
                input = 0;
                break;
        };
    }
}



int main (int argc, const char * argv[])
{
    menuCompresseur();
    return 0;
}