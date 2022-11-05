#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

//Function for reversing the linked list// 
void reverse_linked_list(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}


void append_node(struct Node **head, int value) {  //Append a node with given value at the end of the linked list// 
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


void ranged_reverse(struct Node **head, int k) {
    int iterator = 1;
    struct Node *temp = *head;
    while (iterator < k && temp != NULL) {
        temp = temp->next;
        iterator++;
    }

    // store the next node of the kth node
    struct Node *saved_tail = temp->next;
    temp->next = NULL;

    reverse_linked_list(head);
    
    // Get to end of reversed linked list
    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = saved_tail;
}



/*
* Prints the linked list 
*/
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
    printf("Enter size of list ");
    scanf("%d", &length);

    struct Node *head = NULL;
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        
        int current_val;
        scanf("%d", &current_val);

        append_node(&head, current_val);
    }

    int k;
    printf("Number of nodes to be reversed ");
    scanf("%d", &k);

    printf("Original list ");
    print_linked_list(head);

    ranged_reverse(&head, k);
    printf("After reversing ");
    print_linked_list(head);
}