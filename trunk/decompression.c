#include "decompression.h"

FILE* decompression_decompresse(char* nomFichier)
{
    FILE *fichierComp = NULL, *fichierCodage = NULL, *fichierDecomp = NULL;
    char *nomFichierComp, *nomFichierCodage, *nomFichierDecomp;
    char* extensionFichComp = ".comp", *extensionFichCodage = ".huf", *extensionFichDecomp = ".decomp";
    char *indice = NULL;
    char *frequence = NULL;
    unsigned char* buff;
    unsigned char bitLu;
    int freq[256] = {0};
    int i=0;
    Arbre huffman = NULL, courant = NULL;
    
    
    /* Ouverture du fichier d'informations de codage et test d'ouverture */
    nomFichierCodage=(char*)malloc(strlen(nomFichier)+strlen(extensionFichCodage)+1); /* malloc de nomFichierCodage pour ajouter l'extension */
    strcpy(nomFichierCodage, nomFichier);
    strcat(nomFichierCodage, extensionFichCodage);
    fichierCodage = fopen(nomFichierCodage, "r");  /* Ouverture du fichier */
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
        fgets(indice, 6, fichierCodage);   /* on lit l'indice (si EOF, indice = NULL) */
        fgets(frequence, 1024, fichierCodage);    /* on lit la fréquence correspondante */
        freq[atoi(indice)] = atoi(frequence);	/* atoi : conversion string to int */        
    }
    
    free(indice);
    free(frequence);
    fclose(fichierCodage);  /* Fin des opérations sur fichierCodage */
    
    
    /* Création de l'arbre de Huffman à partir du tableau des fréquences */
    huffman = liste_construitArbre(liste_construitListeArbres(freq));
    
    
    /* Ouverture du fichier compressé et test d'ouverture */
    nomFichierComp=(char*)malloc(strlen(nomFichier)+strlen(extensionFichComp)+1);    /* malloc de nomFichierComp pour ajouter l'extension */
    strcpy(nomFichierComp, nomFichier);
    strcat(nomFichierComp, extensionFichComp);
    fichierComp = fopen(nomFichierComp, "r");   /* Ouverture du fichier */
    free(nomFichierComp);
    if (fichierComp == NULL)        /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    
    /* Creation du fichier décompressé et test d'ouverture */
    nomFichierDecomp=(char*)malloc(strlen(nomFichier)+strlen(extensionFichDecomp)+1);    /* malloc de nomFichierDecomp pour ajouter l'extension */
    strcpy(nomFichierDecomp, nomFichier);
    strcat(nomFichierDecomp, extensionFichDecomp);
    fichierDecomp = fopen(nomFichierDecomp, "w+");
    free(nomFichierDecomp);
    if (fichierDecomp == NULL)        /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    /* On lit fichierComp (en binaire) en parcourant l'arbre de huffman et on écrit dans fichierDecomp */
    courant = huffman;  /* On initialise courant en lui affectant huffman */    
	buff=(unsigned char*)malloc(tailleFichier(fichierComp));
	
	i=0;
	while(!feof(fichierComp))
	{
		buff[i]=fgetc(fichierComp);
		i++;
	}
	/*
	printf("Buff : ");
	for(i=0 ; i<tailleFichier(fichierComp) ; ++i)
	{
		printf("%c", buff[i]);
	}
	printf("\n");
	*/
	for(i=0 ; i<tailleFichier(fichierComp) ; ++i)
	{
		bitLu = litNiemeBit(buff, i);
		printf("Bit lu : %c\n", bitLu);
		
        if (bitLu == '0')
        {
            courant = arbre_fg(courant);
        }
        else if (bitLu == '1')
        {
            courant = arbre_fd(courant);
        }
        
        if (arbre_estFeuille(courant))
        {
			printf("%c", arbre_carRacine(courant));
            fputc(arbre_carRacine(courant), fichierDecomp);
            courant = huffman;
        }
    }
    printf("\n");
    
    fclose(fichierComp);    /* Fin des opérations sur fichierComp */
    free(buff);
    free(huffman);  /* On libère la mémoire utilisée par l'arbre de huffman */
    
    return fichierDecomp;
}
