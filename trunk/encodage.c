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


char** encodage_preEncode(Arbre a, char* construct, char** binaire, int* nbFeuillesTraitees)
{
	/* Parcours de l'arbre
	 * construction d'une chaine de 1 et 0
	 * a chaque car rencontré, copie de la chaine à l'indice ASCII 
	 * retourne le tableau des chaines */
	
	if(*nbFeuillesTraitees==arbre_nbFeuilles(a))
	{
		return binaire;
	}
	
	if(arbre_estFeuille(a))
	{
		binaire[a->c]=(char*)malloc(strlen(construct));
		strcpy(binaire[a->c], construct);
		(*nbFeuillesTraitees)++;
		return binaire;
	}
	
	if(a->fg)
	{
		/* rajouter un 0 a construct et descendre dans le fils gauche */
		strcat(construct, "0");
		return encodage_preEncode(a->fg, construct, binaire, nbFeuillesTraitees);
	}
	if(a->fd)
	{
		/* rajouter un 1 a construct et descendre dans le fils droit */
		strcat(construct, "1");
		return encodage_preEncode(a->fd, construct, binaire, nbFeuillesTraitees);
	}
	
	return NULL;
}


char* encode(Arbre a, char c)
{	
	char** binaire;
	char* construct="";
	int nb=0;
	int* nbFeuillesTraitees=&nb;
	
	binaire=(char**)malloc(256*sizeof(char*));
	
	binaire = encodage_preEncode(a, construct, binaire, nbFeuillesTraitees);
	
	return binaire[(int)c];
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
