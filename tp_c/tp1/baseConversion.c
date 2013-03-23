#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_len(char* s){
    int i;
    for(i=0; s[i]!='\0'; i++){}
    return i;
}

int power(int number, int index){
	int i,tmp=1;
	for(i=0;i<index; i++){
		tmp *= number;
	}

	return tmp;
}

int isLowerCase(char* s){
	int i;

	for(i=0; s[i] != '\0'; i++){
		if(s[i] < 'a' || s[i] > 'z'){
			return 0;
		}
	}

	return 1;
}

int isInt(char* s){
	int i;

	for(i=0; s[i] != '\0'; i++){
		if(s[i] < '0' || s[i] > '9'){
			return 0;
		}
	}

	return 1;
}

int atobase10(char* s){
	int i,j,conversion=0;
	int size = str_len(s);

	for(i=0,j=size-1; i<size; i++,j--){
		/* interprétation en base 26 */
		conversion += ((s[i] - 'a')*power(26,j));
	}

	return conversion;
}

void itobase26(char* s, int n){
	int i,j;
	int c = n;
	int tmp = 0;
	char t[100];

	if(c>=26){
		for(i=0; c>26; i++){
			tmp = c%26;
			c = c/26;
			t[i] = 'a'+tmp;
			printf("%c\n",t[i]);
		}

		for(i=str_len(t),j=0; i>0; i--, j++){
			s[j] = t[i];
		}
	}
	else{
		s[0] = 'a' + n;
	}
}


int main(int argc, char *argv[]){

	if(argc == 1){
		fprintf(stderr,"Usage : un argument uniquement\n");
		exit(1);
	}

	if(isLowerCase(argv[1])){
		printf("%d\n",atobase10(argv[1]));
	}
	else if(isInt(argv[1])){
		char s[100];
		itobase26(s,atoi(argv[1]));
		printf("%s\n",s);
	}
	else{
		fprintf(stderr,"mot en minuscules ou numérique\n");
		exit(1);
	}

	
	return 0;
}
