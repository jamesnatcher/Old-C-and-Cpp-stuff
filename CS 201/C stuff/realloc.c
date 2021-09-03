#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __node_struct_t {
    int value;
    struct __node_struct_t *next; 
} node_t;

node_t *add_to_list(node_t *list, int k){
    node_t *new_node;

    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = k;
    new_node->next = list;
    
    return new_node;
}

void print_list(node_t *list){
    node_t *curr;

    for (curr = list; curr != NULL; curr = curr->next){
        printf("%d\n", curr->value);
    }
}

void delete_list(node_t *list){
    node_t *curr;
    node_t *temp;

    curr = list;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main(void) {
    node_t *list = NULL;
    int k;

    do {
        printf("Please enter a non-negative value: ");
        scanf("%d", &k);
        if (k >= 0) {
            list = add_to_list(list, k);
        }
    } while (k >= 0);

    printf("The list of values is:\n");

    print_list(list);

    delete_list(list);

    printf("The list of values is:\n");

    print_list(list);
    
    return 0;
}