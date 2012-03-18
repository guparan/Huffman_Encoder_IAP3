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


char** encodage_preEncode(Arbre a, int nbFeuilles, char* construct, char** binaire, int* nbFeuillesTraitees, int occurence)
{
	/* Parcours de l'arbre
	 * construction d'une chaine de 1 et 0
	 * a chaque car rencontré, copie de la chaine à l'indice ASCII 
	 * retourne le tableau des chaines */
	char* construct_cpy;	
	construct_cpy=(char*)malloc(strlen(construct)+1);
	strcpy(construct_cpy, construct);
	 
	printf("construct = %s, nbF = %d \n", construct_cpy, (*nbFeuillesTraitees));

	
	if(!construct)
	{
		construct_cpy=(char*)malloc(1*sizeof(char));
	}
	else construct_cpy=(char*)realloc(construct_cpy, strlen(construct)*sizeof(char)+1+1);
	
	if(a->fg)
	{
		/* rajouter un 0 a construct et descendre dans le fils gauche */
		printf("strcat(construct, 0);\n");
		/*strcat(construct, "0");*/
		construct_cpy[occurence]='0';
		construct_cpy[occurence+1]='\0';
		encodage_preEncode(a->fg, nbFeuilles, construct_cpy, binaire, nbFeuillesTraitees, occurence+1);
		
		if((*nbFeuillesTraitees)==nbFeuilles)
		{
			printf("Fin de traitement\n");
			return binaire;
		}
	}
	if(a->fd)
	{
		/* rajouter un 1 a construct et descendre dans le fils droit */
		/*printf("strcat(construct, 1);\n");
		strcat(construct, "1");*/
		construct_cpy[occurence]='1';
		construct_cpy[occurence+1]='\0';
		encodage_preEncode(a->fd, nbFeuilles, construct_cpy, binaire, nbFeuillesTraitees, occurence+1);
		
		if((*nbFeuillesTraitees)==nbFeuilles)
		{
			printf("Fin de traitement\n");
			return binaire;
		}
	}
	
	if(arbre_estFeuille(a))
	{
		printf("Feuille !\n");
		
		binaire[a->c]=(char*)malloc(strlen(construct_cpy)+1);
		strcpy(binaire[a->c], construct_cpy);
		
		(*nbFeuillesTraitees)++;
		
		printf("nbF = %d \n", (*nbFeuillesTraitees));
	}
}


char* encode(char c, char** tabCorrespondance)
{		
	return tabCorrespondance[(int)c];
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
