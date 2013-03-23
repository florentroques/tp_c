#include <stdio.h>
#include <math.h>
#include "complex.h"
#include "list.h"


/*memory est un tableau de cellules*/
Cell memory[TAB_MEMORY_SIZE];

void init_memory(){
	int i;

	for(i=0;i<TAB_MEMORY_SIZE;i++){
		memory[i].next = EMPTY;
	}
}

void print_memory(){
	int i;	

	for(i=0;i<TAB_MEMORY_SIZE;i++){
		if(memory[i].next != EMPTY){
			printf("memory[%d] -> ",i);
			print_complex(memory[i].value);
		}
	}
	printf("\n");
}

int add(int *list, Complex* c){
	int index = get_free_cell();
	if(index == END){
		return 0;
	}

	memory[index].value = c;
	memory[index].next = *list;
	*list = index;
	return 1;
}

void remove_first(int *list){
	printf("memory[%d] ", *list);
	int tmp = memory[*list].next;
	free_cell(*list);
	*list = tmp;
}

void print_list(int list, char* name_list){
	printf("----- liste %s ------\n", name_list);

	while(list != END){
		printf("memory[%d] -> ",list);
		print_complex(memory[list].value);
		list = memory[list].next;
	}
	printf("\n");
}

int get_free_cell(){
	int i;
	for(i=0; i<TAB_MEMORY_SIZE; i++){
		if(memory[i].next == EMPTY){
			return i;
		}
	}
	return END;
}

void free_cell(int index){
	memory[index].next = EMPTY;
}

void free_list(int list){
	int tmp;

	while(list != END){
		tmp = memory[list].next;
		free_cell(list);
		list = tmp;
	}
}
