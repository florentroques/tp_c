#ifndef COLORLIST_H_
#define COLORLIST_H_

#define END -1
#define EMPTY -2
#define COLOR_NAME_MAX 128
#define TAB_COLOR_SIZE 1000

typedef struct{
	char name[COLOR_NAME_MAX];
	int next;
} ColorList;

void init_memory();

void print_memory();

int add_color(int *list, char* color);

void print_list(int list);

int get_free_cell();

void free_cell(int index);

void free_list(int list);

#endif /* COLORLIST_H_ */
