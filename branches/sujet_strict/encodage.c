#include "encodage.h"

void analyseFichier(FILE *fp, int freq[256])
{
	int caractereActuel = 0;
	
	while (caractereActuel != EOF)
	{
		caractereActuel = fgetc(fp);
		freq[caractereActuel] += 1;
	}
}

char* encode(Arbre a, char c)
{		
	int i=0;
	char* bit;
	char* chaine;
	
	if(arbre_estFeuille(a))
	{
		if(arbre_carRacine(a)==c) return "";
		else return "2";
	}
	if(arbre_fg(a))
	{
		chaine=(char*)malloc(512);
		bit=(char*)malloc(512);
		strcpy(bit, "0");
		chaine=strcat(bit, encode(a->fg, c));
		while(chaine[i]!='\0')
		{
			if(chaine[i]=='2')
			{
				break;
			}
			else return chaine;
			i++;
		}
	}
	if(arbre_fd(a))
	{
		chaine=(char*)malloc(512);
		bit=(char*)malloc(512);
		strcpy(bit, "1");
		chaine=strcat(bit, encode(a->fd, c));
		while(chaine[i]!='\0')
		{
			if(chaine[i]=='2')
			{
				break;
			}
			else return chaine;
			i++;
		}
	}
	
}


char decode(Arbre a, char* code)
{
    char res = '\0';
    Arbre courant = a;
    int i = 0;
    
    while (code[i] != '\0')
    {
        if (code[i] == '0')
        {
            courant = arbre_fg(courant);    /*on part dans le fils gauche*/
        }
        else if (code[i] == '1')
        {
            courant = arbre_fd(courant);    /*on part dans le fils droit*/
        }
        else
        {
            return res;     /*on sort de la fonction, le code en paramètre est erroné*/
        }
        i++;    /*passage au caractère suivant dans le code*/
    }
    
    if (arbre_estFeuille(courant))   /*on vérifie que courant est une feuille avant d'affecter la valeur de res*/
    {
        res = arbre_carRacine(courant);
    }
    /*si courant n'est pas une feuille, res est inchangé est vaut '\0'*/
    
    
    return res;
}
