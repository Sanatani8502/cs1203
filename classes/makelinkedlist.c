#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};


void print_linked_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}

//Insert node at the end of linked list 
void append_node(struct Node **head, int value) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;

    // Incase empty list 
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}


int main(void) {
    struct Node *head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 4);
    append_node(&head, 3);
    
    printf("Resultant linked list ");
    print_linked_list(head);
    
}