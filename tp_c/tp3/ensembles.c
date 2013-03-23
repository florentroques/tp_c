#include <stdio.h>
#include <stdlib.h>
#include "bits.h"
#define MAX 2

void init_ensemble(unsigned char *ensemble){
	int i;
	for(i=0;i<MAX;i++){
		(*ensemble)[i]=0;
	}
}

void ajoute(unsigned char *ensemble, int nb_to_add){
	allume_bit((*ensemble)[nb_to_add%8],nb_to_add%8);
}

void affiche_ensemble(unsigned char *ensemble){

}

int appartient(int nb_searched, unsigned char *ensemble){

}

int cardinal(unsigned char *ensemble){
	int nb_elements;

	return nb_elements;
}

void unio(unsigned char *ensemble1, unsigned char *ensemble2){

	(*ensemble1)&(*ensemble2);
}

void intersection(unsigned char *ensemble1, unsigned char *ensemble2){

}

void complementation(unsigned char *ensemble){

}
