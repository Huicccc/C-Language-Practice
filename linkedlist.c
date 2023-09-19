#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int year;
    int wins;
    struct node* next;
}node_t;

node_t* create_node(int year, int wins, node_t* next) {
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->year = year;
    new_node->wins = wins;
    new_node->next = next;
    return new_node;
}

node_t* create_list(int *year, int *wins, int size) {
    node_t* head = NULL;
    node_t* tail = NULL;
    for (int i = 0; i < size; i++) {
        if (head == NULL) {
            head = create_node(year[i], wins[i], NULL);
            tail = head;
        } else {
            tail->next = create_node(year[i], wins[i], NULL);
            tail = tail->next;
        }
    }
    return head;
}

void print_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%d, %d wins\n", current->year, current->wins);
        current = current->next;
    }
}

void free_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        node_t* temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    int year[] = {2018, 2017, 2016, 2015, 2014};
    int wins[] = {108, 93, 93, 78, 71};
    int size = sizeof(year) / sizeof(year[0]);

    node_t* head = create_list(year, wins, size);
    print_list(head);
    free_list(head);
    return 0;
}