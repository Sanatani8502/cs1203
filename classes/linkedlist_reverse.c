#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

//For reversing the list 
void reverse_linked_list(struct LinkedListNode **head) {
    struct Node *prev = NULL;        
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {   //Traverse through the list// 
        next = current->next;     
        current->next = prev;    
        prev = current;
        current = next;
    }
    *head = prev;
}

//Insert a new node at the end of the list// 
void addnode(struct Node **head, int value) {
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


void print_linked_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}

int main(void) {
    int length;
    printf("Size of the list ");
    scanf("%d", &length);

    struct Node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Values "); 
        
        int val;
        scanf("%d", &val);

        addnode(&head, val);
    }

    printf("Before reversal\n");
    print_linked_list(head);

    reverse_linked_list(&head);
    printf("After reversal\n"); 
    print_linked_list(head);
}