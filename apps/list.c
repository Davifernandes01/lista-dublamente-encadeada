#include "list.h"
#include <stdio.h>


int main(){

    List *list = create_doubly_list();
    List *list2 = create_doubly_list();


    list_add_last(list, 10);
    list_add_last(list, 4);
    list_add_last(list, 7);
    list_add_last(list, 2);
    list_add_last(list, 19);
    list_add_last(list, 1064);

   

    list_add_last(list2, 10);
    list_add_last(list2, 4);
    list_add_first(list2, 7);
    list_add_first(list2, 2);
    list_add_last(list2, 19);
    list_add_first(list2, 1064);

    List_print(list2);

    destroy_doubly_list(&list2);
    destroy_doubly_list(&list);
    return 0;
}

