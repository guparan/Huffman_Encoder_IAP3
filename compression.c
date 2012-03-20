#include "compression.h"



float compression_tauxCompression(FILE* init, FILE* comp, FILE* codage)
{
    return (((float)tailleFichier(comp)+(float)tailleFichier(codage))/(float)tailleFichier(init));
}


void compression_compresse(char* nomFichier)
{
	FILE* input;
    FILE *fichierComp = NULL, *fichierCodage = NULL; 
    Arbre huffman;
    char** tabCorres = NULL;
    char *extensionFichComp = ".comp", *extensionFichCodage = ".huf";
    int i = 0, j = 0, freq[256] = {0};
    int nbBit=0;
    char* nomFichierComp;
    char* nomFichierCodage;
    unsigned char* buf;
    unsigned char bit;
    int carLu=0;
    char* codeAssoc;
    int tailleAssoc, positionCourante=0;
    
    if((input=fopen(nomFichier, "ro"))==NULL)
    {
		perror("fopen");
		exit(errno);
	}
    
    /* Init des variables necessaires */
    encodage_analyseFichier(input, freq);
    huffman = liste_construitArbre(liste_construitListeArbres(freq));
    tabCorres = encodage_tabCorrespondance(huffman);
    
    i=1;
    /* Calcul du nombre de bits necessaire a l'encodage */
    while(tabCorres[i]!=NULL)
    {
		if(strcmp(tabCorres[i], "")) 
		{
			/* printf("%d : %s (freq=%d)\n", i, tabCorres[i], freq[i]); */
			nbBit+=freq[i]*(strlen(tabCorres[i]));
		}
		i++;
	}
	/* printf("Nb bits : %d\n", nbBit); */
    buf=(unsigned char*)malloc((nbBit/8)+1);
        
    /* arbre_afficheArbreDot(huffman, "test.dot"); */
    
    /* Ecriture des frequences dans le fichier dédié, nécessaire pour la décompression */
    nomFichierCodage=(char*)malloc(strlen(nomFichier)+strlen(extensionFichCodage)+1);
    strcpy(nomFichierCodage, nomFichier);
    strcat(nomFichierCodage, extensionFichCodage);
    fichierCodage = fopen(nomFichierCodage, "w+");
    free(nomFichierCodage);
    if (fichierCodage == NULL)      /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    for (i=0; i<256; i++)
    {
        if(freq[i]!=0) fprintf(fichierCodage, "%d\n%d\n", i, freq[i]);
    }
    
    /* Creation et ouverture du fichier compresse */
    nomFichierComp=(char*)malloc(strlen(nomFichier)+strlen(extensionFichComp)+1);
    strcpy(nomFichierComp, nomFichier);
    strcat(nomFichierComp, extensionFichComp);
    fichierComp = fopen(nomFichierComp, "wb+");
    free(nomFichierComp);
    if (fichierComp == NULL)      /* Test d'ouverture */
    {
        perror("fopen");
        exit(errno);
    }
    
    /* On remplit buf avec les bits correspondants a chaque caractere du fichier lu */
    i=0;
    while((carLu=fgetc(input))!=EOF)
    {
		codeAssoc=tabCorres[carLu];
		tailleAssoc=strlen(codeAssoc);
		/* printf("Ecriture a la position %d : ", positionCourante); */
		for(j=0 ; j<tailleAssoc ; ++j)
		{
			/* printf("%c", codeAssoc[j]); */
			if(codeAssoc[j]=='0') bit=(unsigned char)0; 
			else bit=(unsigned char)1;
			ecritNiemeBit(buf, bit, positionCourante+j);
		}
		/* printf("\n"); */
		positionCourante+=tailleAssoc;
		i++;
	}
        
	/* On ecrit tous les octets de buf dans le fichier compresse */
	for(i=0 ; i<((nbBit/8)+1) ; ++i)
	{
		fwrite(&buf[i], 1, sizeof(unsigned char), fichierComp);
	}
    
    free(buf);
    
    /* Affichage du taux de compression */
    printf("Taux de compression obtenu: %.5f\n", compression_tauxCompression(input, fichierComp, fichierCodage));
    
    /* Fermeture des fichiers ouverts */
    fclose(input);
    fclose(fichierCodage);
    fclose(fichierComp);
}

