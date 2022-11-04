#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void selection_sort(struct Node **head) {
    struct Node *current = *head;
    while (current != NULL) {
        struct Node *min = current;
        struct Node *j = current->next;
        while (j != NULL) {
            if (j->value < min->value) {
                min = j;
            }
            j = j->next;
        }
        // swap with min with i
        int temp = current->value;
        current->value = min->value;
        min->value = temp;
        current = current->next;
    }
}


void printlinkedlist(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}

void append_node(struct Node **head, int value) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;


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


int main (void) {
    int length;
    printf("Selection Sort Linked List Algorithm\n");
    printf("Enter the number of elements in your list: ");
    scanf("%d", &length);

    struct Node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    printf("Original list: ");
    printlinkedlist(head);

    selection_sort(&head);

    printf("After sorting: ");
    printlinkedlist(head);
}