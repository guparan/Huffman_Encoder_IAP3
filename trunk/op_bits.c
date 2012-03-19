#include "op_bits.h"


int tailleFichier(FILE* fp)
{
    int res = 0;
    fseek(fp, 0, SEEK_END);
    res = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return res;
}


/* n de 0 à 8*(taille buffer) */
void ecritNiemeBit(unsigned char *buff, unsigned char bit, int n) {
	int size_char = sizeof(unsigned char)*8;	/* nb bits par int */
	int nr = n%size_char, nd = n/size_char;
	int masque = 0x1;

	masque <<= (size_char -1 -nr);
	if (bit) { 	/* mise à 1 */
		buff[nd] = buff[nd] | masque;
	} else { /* mise à 0 */
		buff[nd] = buff[nd] & (~masque);
	}

	return;
}


/* n de 0 à 8*(taille buffer) */
/* retour : valeur du nieme bit (0 ou 1) */
unsigned char  litNiemeBit(unsigned char *buff, int n) {
	int size_char = sizeof(unsigned char)*8;	/* nb bits par int */
	int nr = n%size_char, nd = n/size_char;
	unsigned int masque = 0x1;

	masque <<= (size_char -1 -nr);
	return (buff[nd] & masque?1:0);
}
