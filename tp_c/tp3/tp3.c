#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bits.h"
#include "ensembles.h"



void print_test_ex1(){

	int test;
	int pos_test_bit = 4;
	unsigned char test_value = 'a';
	
	print_bin(test_value);
	test = teste_bit(&test_value,pos_test_bit);
	
	printf("le bit %d (de 0 à 7) est %d\n", pos_test_bit, test);
	
	printf("allumage bit %d\n", pos_test_bit);
	allume_bit(&test_value, pos_test_bit);
	test = teste_bit(test_value,pos_test_bit);
	print_bin(test_value);
	printf("le bit %d (de 0 à 7) est %d\n", pos_test_bit, test);
	

	printf("éteignage bit %d\n", pos_test_bit);
	eteint_bit(&test_value, pos_test_bit);
	test = teste_bit(test_value,pos_test_bit);
	print_bin(test_value);
	printf("le bit %d (de 0 à 7) est %d\n", pos_test_bit, test);
	
	
	/*Allumage tout octet*/
	int i;
	for(i=0; i<CHAR_BIT; i++){
		allume_bit(&test_value, i);
	}
	print_bin(test_value);
	
}

void print_test_ex2(){
	unsigned char *ens1;
	init_ensemble(ens1);

}

int main(int argc, char *argv[]){

	/** /
	print_test_ex1();
	/**/
	/**/
	print_test_ex2();
	/**/
	
	

	return 0;
}
