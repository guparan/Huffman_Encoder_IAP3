#include "compression.h"



float compression_tauxCompression(FILE* init, FILE* comp, FILE* codage)
{
    return ((tailleFichier(comp)+tailleFichier(codage))/tailleFichier(init));
}


FILE* compression_compresse(char* nomFichier)
{
	FILE* input;
    FILE *fichierComp = NULL, *fichierCodage = NULL; 
    Arbre huffman;
    char** tabCorres;
    char *extensionFichComp = ".comp", *extensionFichCodage = ".huf";
    int i = 0, j=0;
    int freq[256] = {0};
    int nbCar=0;
    char* nomFichierComp;
    char* nomFichierCodage;
    unsigned char* buf;
    int carLu=0;
    char* codeAssoc;
    int tailleAssoc;
    
    if((input=fopen(nomFichier, "ro"))==NULL)
    {
		perror("fopen");
		exit(errno);
	}
    
    /* Init des variables necessaires */
    nbCar=encodage_analyseFichier(input, freq);
    huffman = liste_construitArbre(liste_construitListeArbres(freq));
    tabCorres = encodage_tabCorrespondance(huffman);    
	buf=(unsigned char*)malloc(nbCar);
	
	arbre_afficheArbreDot(huffman, "test.dot");
    
    /* Ecriture du codage dans le fichier dédié; nécessaire pour la décompression */
    nomFichierCodage=malloc(strlen(nomFichier)+strlen(extensionFichCodage)+1);
    strcpy(nomFichierCodage, nomFichier);
    strcat(nomFichierCodage, extensionFichCodage);
    fichierCodage = fopen(nomFichierCodage, "w+");
    i=0;
    while (tabCorres[i] != NULL)
    {
        if (strcmp(tabCorres[i], ""))
        {
            fprintf(fichierCodage, "%d %s\n", i, tabCorres[i]);
        }
        i++;
    }
    
    /* Creation et ouverture du fichier compresse */
    nomFichierComp=(char*)malloc(strlen(nomFichier)+strlen(extensionFichComp)+1);
    strcpy(nomFichierComp, nomFichier);
    strcat(nomFichierComp, extensionFichComp);
    fichierComp = fopen(nomFichierComp, "wb+");
    
    /* On remplit buf avec l'octet correspondant a chaque caractere du fichier lu */
    /* UN CODE N'EST PAS SUR UN OCTET */
    i=0;
    while((carLu=fgetc(input))!=EOF)
    {
		codeAssoc=tabCorres[carLu];
		tailleAssoc=strlen(codeAssoc);
		if(tailleAssoc!=8)
		{
			for(j=0 ; j<(8-tailleAssoc) ; ++j)
			{
				ecritNiemeBit(buf, '0', (i*8-1)+j);
			}
		}
		for(j=0 ; j<tailleAssoc ; ++j)
		{
			ecritNiemeBit(buf, codeAssoc[j], ((i*8-1)+(8-tailleAssoc+j)));
		}
		/* printf("buf : %s\n", buf[i]); */
		i++;
	}
	
	/* On ecrit tous les octets de buf dans le fichier compresse */
	for(i=0 ; i<nbCar ; ++i)
	{
		fputc(buf[i], fichierComp);
	}
    
    /* Affichage du taux de compression */
    printf("Taux de compression obtenu: %.2f\n", compression_tauxCompression(input, fichierComp, fichierCodage));
    
    return fichierComp;
    
}
