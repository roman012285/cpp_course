#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct List list;

void add_list(list** head, int value);
void delete_head(list** head);
void print_list(list** head);
void delete_list(list** head);

#endif