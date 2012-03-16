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


char** encodage_preEncode(Arbre a, char* construct)
{
	/* Parcours de l'arbre
	 * construction d'une chaine de 1 et 0
	 * a chaque car rencontré, copie de la chaine à l'indice ASCII 
	 * retourne le tableau des chaines */
	char** binaire;
	
	binaire = (char**)malloc(arbre_nbFeuilles(a)*sizeof(char*));
	
	if(arbre_estFeuille(a))
	{
		binaire[a->c]=construct;
	}
	
	if(a->fg)
	{
		/* rajouter un 0 a construct et descendre dans le fils gauche */
		return encodage_preEncode(a->fg, construct);
	}
	if(a->fd)
	{
		/* rajouter un 1 a construct et descendre dans le fils droit */
		return encodage_preEncode(a->fd, construct);
	}
	
}


char* encode(Arbre a, char c)
{
    int i =0;
    char* res = NULL;
    ListeArbres chemin = (ListeArbres)malloc(sizeof(ListeArbres));
    ListeArbres courante = chemin;
    
    chemin->arbre = a;
    chemin->suivant = NULL;
    
    /* Création du chemin:
     while (courante->arbre->c != c) {
        <#statements#>
    }
    */
    
    /* Traduction du chemin: */
    courante = chemin;
    while (courante->suivant != NULL) {
        if (courante->suivant->arbre == arbre_fg(courante->arbre)) {
            res = realloc(res, (i+1)*sizeof(char));
            res[i] = 0;
            i++;
            courante = courante->suivant;
        }
        else if (courante->suivant->arbre == arbre_fd(courante->arbre)) {
            res = realloc(res, (i+1)*sizeof(char));
            res[i] = 1;
            i++;
            courante = courante->suivant;
        }
    }
    res = realloc(res, (i+1)*sizeof(char));
    res[i] = '\0';
    
    return res;
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
