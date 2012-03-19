#include "decompression.h"

FILE* decompression_decompresse(char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL, *fichierDecomp = NULL;
    char *nomFichierCodage = nomFichier, *extensionFichComp = ".comp", *extensionFichCodage = ".huf", *indice = NULL, *frequence = NULL;
    int caractereActuel = 0, freq[256] = {0};
    Arbre huffman = NULL, courant = NULL;
    
    
    /* Ouverture du fichier d'informations de codage et test d'ouverture */
    realloc(nomFichierCodage, strlen(nomFichierCodage)+strlen(extensionFichComp)+1); /* realloc de nomFichierCodage pour ajouter l'extension */
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
    do
    {
        fgets(indice, 4, fichierComp);   /* on lit l'indice (si EOF, indice = NULL) */
        fgets(frequence, 1024, fichierComp);    /* on lit la fréquence correspondante */
        freq[atoi(indice)] = atoi(frequence); /* atoi : conversion string to int */        
    } while (indice != NULL);
    
    free(indice);
    free(frequence);
    fclose(fichierCodage);  /* Fin des opérations sur fichierCodage */
    
    
    /* Création de l'arbre de Huffman à partir du tableau des fréquences */
    huffman = liste_construitArbre(liste_construitListeArbres(freq));
    
    
    /* Ouverture du fichier compressé et test d'ouverture */
    realloc(nomFichier, strlen(nomFichier)+strlen(extensionFichComp)+1);    /* realloc de nomFichier pour ajouter l'extension */
    fichierComp = fopen(strcat(nomFichier, extensionFichComp), "rb");   /* Ouverture du fichier en mode */
    if (fichierComp == NULL)        /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    
    /* Creation du fichier décompressé et test d'ouverture */
    fichierDecomp = fopen(nomFichier, "w+");
    if (fichierDecomp == NULL)        /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    free(nomFichier);
    
    /* On lit fichierComp (en binaire) en parcourant l'arbre de huffman et on écrit dans fichierDecomp */
    courant = huffman;  /* On initialise courant en lui affectant huffman */
    caractereActuel = fgetc(fichierComp);   /* lecture du premier caractère */
    while (caractereActuel != EOF)
    {
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
        caractereActuel = fgetc(fichierComp);
    }
    
    fclose(fichierComp);    /* Fin des opérations sur fichierComp */
    free(huffman);  /* On libère la mémoire utilisée par l'arbre de huffman */
    
    return fichierDecomp;
}
