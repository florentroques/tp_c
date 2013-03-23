#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* CHAR_BIT = 8 -> 1 octet*/

void print_bin(char c){
	int i;

	for(i=CHAR_BIT-1;i>=0; i--){
		printf("%c", (c&(1<<i))?'1':'0');
	}
	printf("\n");
}

int teste_bit(unsigned char c, int pos_bit){

	if(pos_bit>=0 && pos_bit<=7){
		if((c&(1<<(pos_bit)))== 0)
			return 0;

		return 1;
	}
	
	return -1;
}

void allume_bit(char *c, int pos_bit){
	if(pos_bit>=0 && pos_bit<=7)
		*c=(*c)|(1<<pos_bit);
}

void eteint_bit(char *c, int pos_bit){
	if(pos_bit>=0 && pos_bit<=7)
		*c=(*c)&~(1<<pos_bit);
}
