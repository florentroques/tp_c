#include <stdio.h>
#include <stdlib.h>

typedef struct liste{
	int valeur;
	struct liste* suivant;
} Liste;

Liste* allouer(int n){
	Liste* l = (Liste*)malloc(sizeof(Liste));
	if(l == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(1);
	}
	l->valeur = n;
	l->suivant = NULL;

	return l;
}

void liberer_cellule(Liste* l){
	/* Suppression du contenu de la Liste*/
	free(l);
	/* On met l'adresse du pointeur à l'adresse NULL' */
	l = NULL;
}

void liberer_liste(Liste *l){

Liste* tmp = NULL;
do{
	tmp=l->suivant;
	
	liberer_cellule(l);
	l= tmp;
	}
	while(tmp != NULL);
	
	/*
		tmp = *l;
		*l = l->suivant;
		liberer_cellule(tmp);
	*/
}

void afficher_liste(Liste* l){
	while(l != NULL){
		printf("%d\n",l->valeur);
		l = l->suivant;
	}
	printf("\n");
}

void inserer_en_tete(Liste* *l , int n){
	Liste* new_cellule = allouer(n);
	if(new_cellule == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(1);
	}
	
	new_cellule->valeur = n;
	new_cellule->suivant = *l;
	
	*l = new_cellule;	
}

unsigned char* liste_vers_ensemble(Liste* l){

}

Liste* ensemble_vers_liste(unsigned char* e){
	
}

int main(int argc, char **argv) {
	Liste* l1 = allouer(1);
	inserer_en_tete(&l1,2);
	inserer_en_tete(&l1,3);
	inserer_en_tete(&l1,4);
	inserer_en_tete(&l1,5);
	inserer_en_tete(&l1,6);
	
	afficher_liste(l1);
	liberer_cellule(l1);
	afficher_liste(l1);
	liberer_liste(l1);
	afficher_liste(l1);
	
	return 0;
}
