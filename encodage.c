#include "encodage.h"

int encodage_analyseFichier(FILE *fp, int freq[256])
{
	int caractereActuel = 0;
	int nbLus=0;
	
	while (caractereActuel != EOF)
	{
		caractereActuel = fgetc(fp);
		freq[caractereActuel] += 1;
		nbLus++;
	}
	
	fseek(fp, 0, SEEK_SET);
	return nbLus;
}


/* Parcours de l'arbre
 * construction d'une chaine de 1 et 0
 * a chaque car rencontré, copie de la chaine à l'indice ASCII 
 * retourne le tableau des chaines */
char** encodage_construitTabCorres(Arbre a, int nbFeuilles, char* construct, char** binaire, int* nbFeuillesTraitees)
{
	char* construct_cpy;	
	int i=0, j=0;
	
	/* Controle des arguments */
	if(!binaire)
	{
		binaire=(char**)malloc(256*sizeof(char*)+1);    /* +1 pour la sentinelle */
		for(j=0;j<256;++j)
		{
			binaire[j]=(char*)malloc(sizeof(char));
			strcpy(binaire[j],"");
		}
		binaire[256]=NULL;
	}
	if(!nbFeuillesTraitees)
	{
		nbFeuillesTraitees=(int*)malloc(sizeof(int));
		(*nbFeuillesTraitees)=0;
	}
	
	if(!construct)
	{
		construct_cpy=(char*)malloc(1*sizeof(char)+1);
		strcpy(construct_cpy, "");
	}
	else 
	{
		construct_cpy=(char*)malloc(strlen(construct)+2);
		for(i=0 ; construct[i]!='\0' ; ++i)
		{
			construct_cpy[i]=construct[i];
		}
	}
	
	/* Traitement des noeuds */	
	if(arbre_estFeuille(a))
	{		
		construct_cpy[i]='\0';
		binaire[arbre_carRacine(a)]=(char*)realloc(binaire[arbre_carRacine(a)],strlen(construct_cpy)+1);
		strcpy(binaire[arbre_carRacine(a)], construct_cpy);
		(*nbFeuillesTraitees)++;
	}
	else
	{
		if(arbre_fg(a))
		{
			/* rajouter un 0 a construct et descendre dans le fils gauche */
			construct_cpy[i]='0';
			construct_cpy[i+1]='\0';
			encodage_construitTabCorres(arbre_fg(a), nbFeuilles, construct_cpy, binaire, nbFeuillesTraitees);
		}
		if(arbre_fd(a))
		{
			/* rajouter un 1 a construct et descendre dans le fils droit */
			construct_cpy[i]='1';
			construct_cpy[i+1]='\0';
			encodage_construitTabCorres(arbre_fd(a), nbFeuilles, construct_cpy, binaire, nbFeuillesTraitees);
		}
	}	
	
	if((*nbFeuillesTraitees)==nbFeuilles)
	{
		/*free(nbFeuillesTraitees);*/
		free(construct_cpy);
		/*free(construct);*/
		return binaire;
	}
}


char** encodage_tabCorrespondance(Arbre a)
{	
	return encodage_construitTabCorres(a, arbre_nbFeuilles(a), NULL, NULL, NULL);
}


char* encodage_encode(char** tabCorrespondance, char c)
{		
	return tabCorrespondance[(int)c];
}


char encodage_decodeArbre(Arbre a, char* code)
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


char encodage_decode(char** tabCorres, char* code)
{
	int i=0;
	while(tabCorres[i]!=NULL)
	{
		if(strcmp(tabCorres[i], code)==0)
		{
			return (char)i;
		}
		i++;
	}
	fprintf(stderr, "Erreur de decodage : code introuvable");
	exit(-1);
}
