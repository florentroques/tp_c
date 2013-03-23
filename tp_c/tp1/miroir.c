#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Notes:
 * #import <librairie_standard>
 * #import "librairie locale"
 * en compilation -> -I pathIncludes
 *
 * char* tab[] = char** tab car un tableau est une adresse vers la première case
 *
 *
 */


/**
 * Returns the size of a string
 */
int stringSize(char* s){
    if(s == NULL) return -1;
    
    int i;
    for(i=0; s[i]!='\0'; i++){}
    return i;
}

/**
 * Transforms a string in its reverse
 */
void mirror_string(char* s){
	int length = stringSize(s);
    int i;
    char tmp;
    
    for(i=0; i<length/2; i++){
        tmp = s[i];
        s[i] = s[length-i-1];
		s[length-i-1] = tmp;
    }      
}

/**
 * Transforms strings (char*) in an array (char**) into their respective reverse
 */
void mirror_strings(char* array[], int arraySize){
	int i;
	for(i=0; i<arraySize; i++){
		mirror_string(array[i]);
	}
}

int main(int argc, char *argv[]){

	int i;

	if(argc == 1){
		fprintf(stderr,"Usage : Il faut au moins un paramètre\n");
		exit(1);
	}
	
	mirror_strings(argv+1, argc-1);
	
 	for(i=1; i<argc; i++){	
		printf("%s ", argv[i]);
	}
	
	printf("\n");
	
	return 0;
}
