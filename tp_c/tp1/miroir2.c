#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Returns the size of a string
 */
int stringSize(char s[]){
    
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

char * str_replace(const char *search, const char *replace, const char *string){
  char *tok = NULL;
  char *newstr = NULL;
  int lenString = strlen(string);
  int lenSearch = strlen(search);
  int lenReplace = strlen(replace);


  tok = strstr( string, search );
  if( tok == NULL ) return strdup( string );
  newstr = malloc( lenString - lenSearch + lenReplace + 1 );
  if( newstr == NULL ) return NULL;
  memcpy( newstr, string, tok - string );
  memcpy( newstr + (tok - string), replace, lenReplace );
  memcpy( newstr + (tok - string) + lenReplace, tok + lenReplace, lenString - lenSearch - ( tok - string ) );
  memset( newstr + lenString - lenSearch + lenReplace, 0, 1 );
  return newstr;
}

int main(int argc, char *argv[]){

	int i;
	
	if(argc == 1){
		fprintf(stderr,"Usage : Il faut au moins un paramètre\n");
		exit(1);
	}
	
	mirror_strings(argv+1, argc-1);
	
 	for(i=argc-1; i>0; i--){

 		if(i>1){
 			printf("%s_", argv[i]);
 		}
 		else{
			printf("%s", argv[i]);
		}
	}

 	char s[50];
 	for(i=argc-1; i>0; i--){
 		strcat(s,argv[i]);
 	}

 	printf("%s",str_replace(" ","_",s));
	
	printf("\n");
	
	return 0;
}
