//
//  compression.c
//  Compresseur
//
//  Created by Lucas Saurel on 16/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

int tailleFichier(FILE* fp)
{
    int res = 0;
    fseek(fp, 0, SEEK_END);
    res = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return res;
}


float tauxCompression(FILE* init, FILE* comp)
{
    return (tailleFichier(comp)/tailleFichier(init));
}