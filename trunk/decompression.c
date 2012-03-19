#include "decompression.h"

FILE* decompression_decompresse(char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL, *fichierDecomp = NULL;
    char *nomFichierComp, *nomFichierCodage, *nomFichierDecomp;
    char* extensionFichComp = ".comp", *extensionFichCodage = ".huf", *extensionFichDecomp = ".decomp";
    char *indice = NULL;
    char *frequence = NULL;
    int caractereActuel = 0, freq[256] = {0};
    Arbre huffman = NULL, courant = NULL;
    
    
    /* Ouverture du fichier d'informations de codage et test d'ouverture */
    nomFichierCodage=(char*)malloc(strlen(nomFichier)+strlen(extensionFichCodage)+1); /* malloc de nomFichierCodage pour ajouter l'extension */
    strcpy(nomFichierCodage, nomFichier);
    fichierCodage = fopen(strcat(nomFichierCodage, extensionFichCodage), "r");  /* Ouverture du fichier */
    free(nomFichierCodage);
    if (fichierCodage == NULL)      /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    
   /* Création de la table des fréquences à utiliser (par lecture de fichierCodage) */
    indice = malloc(10*sizeof(char));
    frequence = malloc(1024*sizeof(char));
    while (!feof(fichierCodage))
    {
        fgets(indice, 6, fichierCodage);   /* on lit l'indice */
        fgets(frequence, 1024, fichierCodage);    /* on lit la fréquence correspondante */
        freq[atoi(indice)] = atoi(frequence); /* atoi : conversion string to int */        
    }
    
    free(indice);
    free(frequence);
    fclose(fichierCodage);  /* Fin des opérations sur fichierCodage */
    
    
    /* Création de l'arbre de Huffman à partir du tableau des fréquences */
    huffman = liste_construitArbre(liste_construitListeArbres(freq));

    
    /* Ouverture du fichier compressé et test d'ouverture */
    nomFichierComp=(char*)malloc(strlen(nomFichier)+strlen(extensionFichComp)+1);    /* malloc de nomFichierComp pour ajouter l'extension */
    strcpy(nomFichierComp, nomFichier);
    free(nomFichierComp);
    fichierComp = fopen(strcat(nomFichierComp, extensionFichComp), "rb");   /* Ouverture du fichier en mode */
    if (fichierComp == NULL)        /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    /* Creation du fichier décompressé et test d'ouverture */
    nomFichierDecomp=(char*)malloc(strlen(nomFichier)+strlen(extensionFichDecomp)+1);    /* malloc de nomFichierDecomp pour ajouter l'extension */
    strcpy(nomFichierDecomp, nomFichier);
    fichierDecomp = fopen(strcat(nomFichierDecomp, extensionFichDecomp), "w+");
    free(nomFichierDecomp);
    if (fichierDecomp == NULL)        /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    /* On lit fichierComp (en binaire) en parcourant l'arbre de huffman et on écrit dans fichierDecomp */
    courant = huffman;  /* On initialise courant en lui affectant huffman */
    
    while (!feof(fichierComp))
    {
        caractereActuel = fgetc(fichierComp);   /* lecture d'un caractère */
        if (caractereActuel == '0')
        {
            courant = arbre_fg(courant);
        }
        else if (caractereActuel == '1')
        {
            courant = arbre_fd(courant);
        }
        
        if (arbre_estFeuille(courant))
        {
            fputc(arbre_carRacine(courant), fichierDecomp);
            courant = huffman;
        }
    }
    
    fclose(fichierComp);    /* Fin des opérations sur fichierComp */
    free(huffman);  /* On libère la mémoire utilisée par l'arbre de huffman */

    return fichierDecomp;
}
