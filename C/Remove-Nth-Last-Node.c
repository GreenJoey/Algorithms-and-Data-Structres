#include <stdio.h>
#include <stdlib.h>


typedef struct list_t {
    int data;
    struct list_t *next;
} list_t;


void append(list_t **list, int data) {
    if(*list)
        append(&(*list)->next, data);
    else {
        *list = (list_t *)malloc(sizeof(list_t));
        (*list)->data = data;
        (*list)->next = NULL;
    }
}


list_t *remove_last(list_t *list, int pos) {
    list_t *head_p, *tail_p;
    head_p = tail_p = list;

    for(int i=1; i<=pos && tail_p != NULL; ++i)
        tail_p = tail_p->next;

    while(tail_p->next != NULL) {
        head_p = head_p->next;
        tail_p = tail_p->next;
    }

    tail_p = head_p->next->next;
    free(head_p->next);
    head_p->next = tail_p;

    return list;
}


void print(list_t *list) {
    list_t *tmp;
    while(list) {
        printf("%d", list->data);
        if(list->next)
            printf("->");
        tmp = list->next;
        list = tmp;
    }
    printf("\n");
}


int main() {
    list_t *list = NULL;

    for(int i=1; i<=5; ++i)
        append(&list, i);

    print(list);

    list = remove_last(list, 2);
    print(list);
    list = remove_last(list, 3);
    print(list);

    return 0;
}
