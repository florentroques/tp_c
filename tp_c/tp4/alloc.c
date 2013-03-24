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

Liste* liberer_cellule(Liste* l){
	if(l != NULL){
		Liste* suite = l->suivant;
		/* Suppression du contenu de la Liste*/
		free(l);
		/* On met l'adresse à NULL' */
		l=NULL;
		return suite;
	}

	return NULL;
}

Liste* liberer_liste(Liste *l){
	Liste* tmp_suivant = NULL;

	while(l != NULL){
		tmp_suivant = l->suivant;

		liberer_cellule(l);
		l = tmp_suivant;
	}

	liberer_cellule(l);
	l = NULL;
}

void afficher_liste(Liste* l){
	while(l != NULL){
		printf("%d ",l->valeur);
		l = l->suivant;
	}
	printf("\n");
}


Liste* inserer_en_tete(Liste* *l , int n){
	Liste* new_cellule = allouer(n);
	if(new_cellule == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(1);
	}
	
	new_cellule->valeur = n;
	new_cellule->suivant = *l;
	
	*l = new_cellule;
	return new_cellule;
}


unsigned char* liste_vers_ensemble(Liste* l){

}

Liste* ensemble_vers_liste(unsigned char* e){
	
}

int main(int argc, char **argv) {
	Liste* l1 = allouer(1);

	/**/
	Liste* l2 = inserer_en_tete(&l1,2);
	Liste* l3 = inserer_en_tete(&l1,3);
	Liste* l4 = inserer_en_tete(&l1,4);
	Liste* l5 = inserer_en_tete(&l1,5);
	Liste* l6 = inserer_en_tete(&l1,6);
	/**/

    /** /
	Liste* l2 = inserer_en_tete(l1,2);
	Liste* l3 = inserer_en_tete(l1,3);
	Liste* l4 = inserer_en_tete(l1,4);
	Liste* l5 = inserer_en_tete(l1,5);
	Liste* l6 = inserer_en_tete(l1,6);
	/**/
	
	afficher_liste(l1);
	l1 = liberer_liste(l1);
	afficher_liste(l1);
	l1 = allouer(1);
	inserer_en_tete(&l1,2);
	afficher_liste(l1);
	/**/
	return 0;
}
