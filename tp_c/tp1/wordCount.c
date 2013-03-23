#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct counter{
	int nbChar;
	int nbWords;
	int nbLines;
};

void wc(struct counter* cpt){
	
	cpt->nbChar 	= 0;
	cpt->nbWords	= 0;
	cpt->nbLines	= 1;
	char c = getchar();
	
	while(c != EOF){	

		if(c== ' ' || c== '\t'){
			cpt->nbWords++;
		}
		else if(c=='\n'){
			cpt->nbLines++;
		}
		else cpt->nbChar++;
		
		c = getchar();
	}
}

int comptage(int *nc, int *nw, int *nl){
	char c;
	*nc=0; *nw=0; *nl=0;

	while(!feof(stdin)){
		c = (char) fgetc(stdin);
		if(c== ' ' || c== '\t') (*nw)++;
		else if(c=='\n') (*nl)++;
		else (*nc)++;
	}
	
	return 0;
}



int main(int argc, char *argv[]){
	/**/
	int nw, nc, nl;
	comptage(&nc, &nw, &nl);
	printf("\n");
	printf("Nombre de caractères %d\n"	, nc);
	printf("Nombre de mots %d\n"		, nw);
	printf("Nombre de lignes %d\n"		, nl);
	/**/
	/** /
	struct counter cpt;
	wc(&cpt);
	printf("\n");
	printf("Nombre de caractères %d\n"	, cpt.nbChar);
	printf("Nombre de mots %d\n"		, cpt.nbWords);
	printf("Nombre de lignes %d\n"		, cpt.nbLines);
	/**/
	
	return 0;
}
