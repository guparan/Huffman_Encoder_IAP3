#include <encodage.h>


/**
 * \fn void analyseFichier(FILE *fp, int freq[256])
 * \brief Remplit le tableau freq avec le nombre d'occurences de chaque caractère du fichier pointé par fp
 * 
 * \param fp pointeur sur un fichier déjà ouvert avant d'appeler la fonction
 * \param freq pointeur sur un tableau de 256 entiers initialisés à 0
 **/
void analyseFichier(FILE *fp, int freq[256])
{
	int caractereActuel = 0;
	
	do
	{
		caractereActuel = fgetc(fp);
		freq[caractereActuel] += 1;
	} while (caractereActuel != EOF);
}