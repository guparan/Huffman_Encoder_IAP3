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
 * \file tests.c
 **/

#include "arbre.h"
#include "listeArbres.h"
#include "encodage.h"
#include "op_bits.h"
#include "compression.h"
#include "decompression.h"
#include "tests.h"


void menuCompresseur()
{
    char choix[100], nomFichier[100];
    int input = 0;
    
    while (input != 9)
    {
        printf("\n=== Programme de compression/décompression de fichiers === \n\t1. [Test] Afficher arbre de Huffman\n\t2. Compresser un fichier\n\t3. Décompresser un fichier\n\t9. Quitter\n\n");
        scanf("%s", choix);
        input=atoi(choix);
        
        switch(input)
        {
            case 1:
                printf("Nom du fichier à analyser (extension comprise) : ");
                scanf("%s", nomFichier);
                test_afficheArbreDot(nomFichier);  
                input = 0;
                break;
            case 2:
                printf("Nom du fichier à compresser (extension comprise) : ");
                scanf("%s", nomFichier);
                compression_compresse(nomFichier);
                input = 0;
                break;
            case 3:
                printf("Nom du fichier à décompresser (extension NON comprise) : ");
                scanf("%s", nomFichier);
                decompression_decompresse(nomFichier);
                input = 0;
                break;
            case 9:
                printf("A bientôt\n");
                break;
            default:
                printf("Ce choix n'existe pas\n\n");
                input = 0;
                break;
        };
    }
}



int main (int argc, const char * argv[])
{
	/*test_compresse();*/
	
    menuCompresseur();
    return 0;
}
