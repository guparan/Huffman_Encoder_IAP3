#include "encodage.h"

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
	
	arbre_afficheArbreDot(arbre, "test.dot");
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


void test_analyseFichier(void)
{
	int freq[256]={0};
	ListeArbres liste;
	Arbre result;
	FILE* fichier;
	
	fichier=fopen("./test.txt", "ro");
	
	analyseFichier(fichier, freq);
	
	liste=liste_construitListeArbres(freq);
	
	liste_afficher(liste);
	
	result=liste_construitArbre(liste);
	
	arbre_afficheArbreDot(result, "test.dot");
	
}


void test_construitArbre(void)
{
	
}


int main (void)
{
	test_analyseFichier();
	return 0;
}
