#include <stdio.h>
#include <math.h>
#include <string.h>
#include "colorlist.h"


/*memory est un tableau de cellules*/
ColorList memory[TAB_COLOR_SIZE];

void init_memory(){
	int i;

	for(i=0;i<TAB_COLOR_SIZE;i++){
		if(i != TAB_COLOR_SIZE -1){
			memory[i].next = EMPTY;
		}
		else{
			memory[i].next = END;
		}
	}
}

void print_memory(){
	int i;

	for(i=0;i<TAB_COLOR_SIZE;i++){
		if(memory[i].next != EMPTY ){
			printf("%s ", memory[i].name);
		}
	}
	printf("\n");
}

int add_color(int *list, char* color){
	int index = get_free_cell();
	if(index == END){
		return 0;
	}

	strcpy(memory[index].name, color);
	memory[index].next = (*list);
	(*list) = index;
	return 1;
}

void print_list(int list){
	printf("list = ");

	while(list != END){
		printf("%s ", memory[list].name);
		list = memory[list].next;
	}
	printf("\n");
}

int get_free_cell(){
	int i;
	for(i=0; i<TAB_COLOR_SIZE; i++){
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
