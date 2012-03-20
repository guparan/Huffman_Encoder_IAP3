#include "tests.h"

void my_display(unsigned char c, int f)
{
	if(c!='\0')	printf("%c=", c);
	printf("%d \n", f);
}


Arbre test_enracArbre(void)
{
	Arbre a = arbre_creerFeuille('a', 3);
	Arbre b = arbre_creerFeuille('b', 4);
	Arbre c = arbre_creerFeuille('c', 5);
	Arbre d = arbre_creerFeuille('d', 6);
	
	return arbre_enrac(arbre_enrac(a, b), arbre_enrac(c, d));
}


void test_afficheArbre(void)
{
	Arbre arbre = test_enracArbre();
	
	arbre_afficheArbre(arbre_fg(arbre), my_display);
	
	arbre_afficheArbreDot(arbre, "arbre_grosFichier.dot");
}


void test_insererTriArbre(void)
{
	Arbre a = arbre_creerFeuille('a', 3);
	Arbre b = arbre_creerFeuille('b', 4);
	
	ListeArbres l = liste_creer();
	
	liste_afficher(l);
	
	l=liste_insererTriArbre(l, a);
	l=liste_insererTriArbre(l, b);
	
	liste_afficher(l);
}


void test_encodage_analyseFichierConstruitArbre(void)
{
	int freq[256]={0};
	ListeArbres liste;
	Arbre result;
	FILE* fichier;
	
	fichier=fopen("./grosFichier", "ro");
    if (fichier == NULL)
    {
        perror("fopen");
        exit(errno);
    }
	
	encodage_analyseFichier(fichier, freq);
	
	liste=liste_construitListeArbres(freq);
	
	liste_afficher(liste);
	
	result=liste_construitArbre(liste);
	
	arbre_afficheArbreDot(result, "arbre_grosFichier.dot");
	
	printf("%d feuilles !\n", arbre_nbFeuilles(result));
}


void test_encode(void)
{	
	
	char** binaire;
	int i=0;
	int freq[256]={0};
	ListeArbres liste;
	Arbre result;
	FILE* fichier;
	
	fichier=fopen("./grosFichier", "ro");
	if (fichier == NULL)
    {
        perror("fopen");
        exit(errno);
    }
	encodage_analyseFichier(fichier, freq);	
	liste=liste_construitListeArbres(freq);	
	result=liste_construitArbre(liste);
	
	arbre_afficheArbreDot(result, "test");

	binaire = encodage_tabCorrespondance(result);
	
	/*for(i=0;i<256;++i)*/
	while(binaire[i]!=NULL)
	{
		/* strcmp retourne 0 si match */
		if(strcmp(binaire[i],"")!=0) printf("%d : %s\n", i, binaire[i]);
		++i;
	}
}


void test_decode(void)
{
    int freq[256]={0};
	Arbre result;
	char** binaire;
	FILE* fichier;
	
	fichier=fopen("./grosFichier", "ro");
    if (fichier == NULL)
    {
        perror("fopen");
        exit(errno);
    }
    
    encodage_analyseFichier(fichier, freq);
		
	result=liste_construitArbre(liste_construitListeArbres(freq));
    
    printf("Le code correspond au caractère : %d\n", encodage_decodeArbre(result, "10010"));
    
	binaire = encodage_tabCorrespondance(result);    
	printf("Test u : %c\n", encodage_decode(binaire, encodage_encode(binaire, 'u')));	
}


void test_compresse(void)
{
	compression_compresse("./grosFichier");	
	
	/*decompression_decompresse("./grosFichier");*/
}
