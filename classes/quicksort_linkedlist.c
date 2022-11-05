#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void printlinkedlist(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf(" %d ->", current->value);
        current = current->next;
    }
    printf(" None \n");
}

//Insert a node at the end of the list// 
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

struct Node* partition(struct Node *start, struct Node *end) { //Returns pointer to the partition node// 

    struct Node *pivot = start;
    struct Node *current = start;

    while (current != end) {
        if (current->value < end->value) {
            pivot = start;

            int temp = pivot->value;
            start->value = current->value;
            current->value = temp;

            start = start->next;
        }
        current = current->next;
    }
    
    int temp = start->value;
    start->value = end->value;
    end->value = temp;
    return pivot;
}

void quick_sort(struct Node *start, struct Node *end) {
    if (start == end) {
        return;
    }
    struct Node *part = partition(start, end);
    quick_sort(start, part);
    quick_sort(part->next, end);
}


int main (void) {
    int size;
    printf("Size of the list ");
    scanf("%d", &size); 

    struct Node *head = NULL;
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    printf("The unsorted linked list is: ");
    printlinkedlist(head);

    struct Node *tail_node = head;
    while (tail_node->next != NULL) {
        tail_node = tail_node->next;
    }

    quick_sort(head, tail_node);

    printf("The sorted linked list is: ");
    printlinkedlist(head);
}