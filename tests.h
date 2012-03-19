#ifndef TESTS_H
#define TESTS_H

#include "arbre.h"
#include "listeArbres.h"
#include "encodage.h"
#include "op_bits.h"
#include "compression.h"
#include "decompression.h"

void my_display(unsigned char c, int f);

Arbre test_enracArbre(void);

void test_afficheArbre(void);

void test_insererTriArbre(void);

void test_encodage_analyseFichierConstruitArbre(void);

void test_encode(void);

void test_decode(void);

void test_compresse(void);


#endif
