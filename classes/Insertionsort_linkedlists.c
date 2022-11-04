#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

//Function to insert a given value into the linked list// 
void insert_node(struct Node **head, int value) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;

    // If list is empty //
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

//Function for sorting linked list from a pointer to a pointer to its head //
void insertion_sort(struct Node **head) {
    struct Node *current = *head;
    while (current != NULL) {

        struct Node *currentprevious = current;  //Must track the previous value of current for insertion//
        struct Node *j = current->next; 

        while (j != NULL) {
            if (j->value < currentprevious->value) {
                currentprevious = j;
            }
            j = j->next;
        }
        
        // Swap previous current value with 'i' 
        int temp = current->value;
        current->value = currentprevious->value;
        currentprevious->value = temp;
        current = current->next;
    }
}


int main (void) {
    int length;
    printf("\n Length of linked list: ");
    scanf("%d", &length);

    struct Node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Values %d: ", i + 1); 
        
        int value;
        scanf("%d", &value);

        append_node(&head, value);
    }

    printf("\n Linked List \n"); 
    print_linked_list(head);

    insertion_sort(&head);

    printf("\n After Sorting \n"); 
    print_linked_list(head);
}