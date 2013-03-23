#ifndef LIST_H
#define LIST_H

#define END -1
#define EMPTY -2
#define TAB_MEMORY_SIZE 255

/**
 Valeurs de next particulières :
 
    END (-1) indiquant que la cellule courante n'a
    pas de cellule suivante.
    EMPTY (-2) indiquant que la cellule n'appartient
    à aucune chaîne (pas de valeur et pas de cellule suivante).
 */
typedef struct{
	Complex* value;
	int next;
} Cell;

void init_memory();

void print_memory();

int add(int *list, Complex* c);

void remove_first(int *list);

void print_list(int list, char* name_list);

int get_free_cell();

void free_cell(int index);

void free_list(int list);

Complex get_complex(int pos);

int get_next(int pos);

#endif
