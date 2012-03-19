#include "compression.h"



float compression_tauxCompression(FILE* init, FILE* comp, FILE* codage)
{
    return ((tailleFichier(comp)+tailleFichier(codage))/tailleFichier(init));
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
    
    /* TEST 
		tabCorres=(char**)malloc(256*sizeof(char*)+1);
		for(j=0;j<256;++j)
		{
			tabCorres[j]=(char*)malloc(sizeof(char));
			strcpy(tabCorres[j],"");
		}
		tabCorres[256]=NULL;		
		tabCorres[116]="1";
		tabCorres[101]="01";
		tabCorres[115]="00";
		
		freq[116]=2;
		freq[101]=1;
		freq[115]=1;
    
    huffman = liste_construitArbre(liste_construitListeArbres(freq));
    */
    
    i=1;
    while(tabCorres[i]!=NULL)
    {
		if(strcmp(tabCorres[i], "")) 
		{
			printf("%d : %s (freq=%d)\n", i, tabCorres[i], freq[i]);
			nbBit+=freq[i]*(strlen(tabCorres[i]));
		}
		i++;
	}
	printf("Nb bits : %d\n", nbBit);
    buf=(unsigned char*)malloc(nbBit);
        
    arbre_afficheArbreDot(huffman, "test.dot");
    
    /* Ecriture des frequences dans le fichier dédié, nécessaire pour la décompression */
    nomFichierCodage=(char*)malloc(strlen(nomFichier)+strlen(extensionFichCodage)+1);
    strcpy(nomFichierCodage, nomFichier);
    strcat(nomFichierCodage, extensionFichCodage);
    fichierCodage = fopen(nomFichierCodage, "w+");
    
    for (i=0; i<256; i++)
    {
        if(freq[i]!=0) fprintf(fichierCodage, "%d\n%d\n", i, freq[i]);
    }
    free(nomFichierCodage);
    fclose(fichierCodage);
    
    /* Creation et ouverture du fichier compresse */
    nomFichierComp=(char*)malloc(strlen(nomFichier)+strlen(extensionFichComp)+1);
    strcpy(nomFichierComp, nomFichier);
    strcat(nomFichierComp, extensionFichComp);
    fichierComp = fopen(nomFichierComp, "wb+");
    
    /* On remplit buf avec l'octet correspondant a chaque caractere du fichier lu */
    i=0;
    while((carLu=fgetc(input))!=EOF)
    {
		codeAssoc=tabCorres[carLu];
		tailleAssoc=strlen(codeAssoc);
		for(j=0 ; j<tailleAssoc ; ++j)
		{
			printf("%c", codeAssoc[j]);
			ecritNiemeBit(buf, codeAssoc[j], positionCourante+j);
		}
		/* printf("buf : %s\n", buf[i]); */
		positionCourante=j;
		i++;
	}
        
	/* On ecrit tous les octets de buf dans le fichier compresse */
	printf("\n");
	for(i=0 ; i<nbBit ; ++i)
	{
		afficher_binaire(buf[i]);
		fputc(buf[i], fichierComp);
	}

    /* Affichage du taux de compression */
    printf("Taux de compression obtenu: %.2f\n", compression_tauxCompression(input, fichierComp, fichierCodage));
    
    fclose(fichierComp);
}

