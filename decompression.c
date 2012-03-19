#include "decompression.h"

FILE* decompression_decompresse(char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL, *fichierDecomp = NULL;
    char *nomFichierCodage = nomFichier, *extensionFichComp = ".comp", *extensionFichCodage = ".huf", *buffer = NULL;
    int caractereActuel = 0, i = 0, j = 0, freq[256];
    Arbre huffman = NULL, courant = NULL;
    
    
    /* Ouverture du fichier d'informations de codage et test d'ouverture */
    realloc(nomFichierCodage, strlen(nomFichierCodage)+strlen(extensionFichComp)+1); /* realloc de nomFichierCodage pour ajouter l'extension */
    fichierCodage = fopen(strcat(nomFichierCodage, extensionFichCodage), "r");  /* Ouverture du fichier */
    if (fichierCodage == NULL)      /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    
   /* Création de la table des fréquences à utiliser (par lecture de fichierCodage) */
    while (caractereActuel != EOF)
    {
        caractereActuel = fgetc(fichierComp);   /* on lit l'indice (ou EOF si on est à la fin du fichier) */
        if (caractereActuel != EOF)
        {
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
    }
    
    fclose(fichierCodage);  /* Fin des opérations sur fichierCodage */
    
    
    /* Création de l'arbre de Huffman à partir du tableau des fréquences */
    huffman = liste_construitArbre(liste_construitListeArbres(freq));
    
    
    /* Ouverture du fichier compressé et test d'ouverture */
    realloc(nomFichier, strlen(nomFichier)+strlen(extensionFichComp)+1);    /* realloc de nomFichier pour ajouter l'extension */
    fichierComp = fopen(strcat(nomFichier, extensionFichComp), "rb");   /* Ouverture du fichier */
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
    
    
    /* On lit fichierComp (en binaire) en parcourant l'arbre de huffman et on écrit dans fichierDecomp */
    caractereActuel = 0;    /* Réinitialisation de caractereActuel pour la lecture de fichierComp */
    while (caractereActuel != EOF)
    {
        courant = huffman;
        caractereActuel = fgetc(fichierComp);
        if (caractereActuel == '0')
        {
            courant = arbre_fg(courant);
        }
        else if (caractereActuel == '1')
        {
            courant = arbre_fd(courant);
        }
    }
    
    fclose(fichierComp);    /* Fin des opérations sur fichierComp */
    
    return fichierDecomp;
}
