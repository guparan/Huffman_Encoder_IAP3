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
        if (courante->suivant->arbre == courante->arbre->fg) {
            res = realloc(res, (i+1)*sizeof(char));
            res[i] = 0;
            i++;
            courante = courante->suivant;
        }
        else if (courante->suivant->arbre == courante->arbre->fd) {
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
    char res;
    Arbre courant = a;
    int i = 0;
    
    while (code[i] != '\0')
    {
        if (code[i] == 0)
        {
            courant = courant->fg;
        }
        else  /* si code[i] == 1 */
        {
            courant = courant->fd;
        }
        i++;
    }
    
    if (courant->c)
    {
        res = courant->c;
    }
    
    return res;
}