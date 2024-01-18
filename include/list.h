#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct _doubly_list List;
typedef struct _doubly_node Node;

Node *create_doubly_node(int val);
List *create_doubly_list();
void destroy_doubly_list(List **list);
bool list_is_empty(const List *list);
void list_add_first(List *list, int val);
void List_print(const List *list);
void List_print_inverted(const List *list);
void list_add_last(List *list, int val);





#endif