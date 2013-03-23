#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "complex.h"
#include "list.h"

unsigned time_seed(){
	time_t now = time ( 0 );
	unsigned char *p = (unsigned char *)&now;
	unsigned seed = 0;
	size_t i;

	for ( i = 0; i < sizeof now; i++ ){
		seed = seed * ( UCHAR_MAX + 2U ) + p[i];
	}

	return seed;
}

float uniform_deviate ( int seed ){
	return seed * ( 1.0 / ( RAND_MAX + 1.0 ) );
}
int max_rand(int max){
	return uniform_deviate ( rand() ) * max;
}

int interval_rand(int min, int max){
	return min + uniform_deviate ( rand() ) * ( max - min );
}

float funiform_deviate ( int seed ){
	return seed * ( 1.0 / ( RAND_MAX + 1.0f) );
}
float max_frand(float max){
	return funiform_deviate(rand()) * max;
	/*return (rand() / (RAND_MAX + 1.0f)) * max;*/
}
float interval_frand(float min, float max){
	 return min + (rand() / (RAND_MAX + 1.0f)) * (max - min);
}

Complex c20(){
 return new_complex(max_frand(20.0), max_frand(20.0));
}

int main(int argc, char *argv[]){

	extern Cell memory[TAB_MEMORY_SIZE];
	/* Initalisation rand et valeurs complexes */
	srand(time_seed());
	Complex c1 = c20();
	Complex c2 = c20();
	Complex c3 = c20();
	Complex c4 = c20();
	Complex c5 = c20();
	Complex c6 = c20();
	Complex c7 = c20();
	Complex c8 = c20();
	Complex c9 = c20();

	/*1. Tests fonctions nombres complexes* /
	print_complex(&c1);
	
	Complex c_sum = sum(&c1,&c2);
	print_complex(&c_sum);
	
	Complex c_conj = conjugate(&c1);
	print_complex(&c_conj);
	
	float c_norm = norm(&c1);
	printf("norme: %f\n",c_norm);	
	/**/
	
	/*2. liste chainée 5 nb cplx et affichage* /
	
	init_memory();
	int list = END;
	add(&list,&c1);
	add(&list,&c2);
	add(&list,&c3);
	add(&list,&c4);
	add(&list,&c5);
	print_list(list);
	print_memory();
	free_list(list);
	list=END;
	print_list(list);
	/**/
	
	/*3. Créa liste1, liste2 ajout suppression cellules* /
	init_memory();

	int l1 = END;
	printf("ajout 5 cellules à l1\n");
	add(&l1,&c1);
	add(&l1,&c2);
	add(&l1,&c3);
	add(&l1,&c4);
	add(&l1,&c5);
	print_memory();

	int l2 = END;
	printf("ajout 2 cellules à l2\n");
	add(&l2,&c6);
	add(&l2,&c7);
	print_memory();

	printf("suppression 3 cellules de l1\n");
	remove_first(&l1);
	remove_first(&l1);
	remove_first(&l1);
	printf("\n\n");
	print_memory();

	printf("ajout 1 cellule à l2\n");
	add(&l2,&c8);
	print_memory();

	printf("ajout 1 cellule à l1\n");
	add(&l1,&c9);
	print_memory();

	print_list(l1,"l1");
	print_list(l2,"l2");

	printf("Dernier index l1 = %d, l2 = %d\n", l1, l2);
	/**/

	/*4. Calcul somme conjugués */
	int l1 = END;
	add(&l1,&c1);
	add(&l1,&c2);
	add(&l1,&c3);
	add(&l1,&c4);
	add(&l1,&c5);
	print_memory();

	int l2 = END;
	add(&l2,&c6);
	add(&l2,&c7);
	print_memory();
	/**/
	/* Test ColorList * /
	extern ColorList memory[TAB_COLOR_SIZE];
	init_memory();
	int list = END;
	add_color(&list, "blue");
	add_color(&list, "black");
	add_color(&list, "red");
	print_list(list);
	print_memory();
	free_list(list);
	list=END;
	print_list(list);
	/**/
	
	return 0;
}
