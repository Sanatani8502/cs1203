#include <stdio.h> 
#include <stdlib.h> 


void printarray (int* a, int size){
    for (int i = 0; i<size; i++){
        printf(" %d ", a[i]);  
    }
    printf("\n"); 
}


typedef struct stack {

    int* data; 
    int top; //index where top is at// 
    int size; 

}S; 


void print_stack (S* stackz){

    printf ("\n"); 

    for (int i = 0; i <= stackz->top; i++){

        printf(" %d ", stackz->data[i]);   

    } 

    printf ("\n"); 

}

S* create_stack (int length){   

   S* stackz = (S*) malloc (sizeof(S));   

   stackz->top = -1; //empty stack// 

   stackz->data = (int*) malloc (length*sizeof(int));
   stackz->size = length; 

   return stackz; 

}

void free_stack (S* stack){

    free (stack->data); 
    free (stack); 

}

void push (S* stack, int val){

    ++stack->top; 

    if (stack->top >= stack->size){

        printf ("\n The stack is full! \n"); 
        return; 

    }

    stack->data [stack->top] = val; 

}

int extract (S* stack){

    if (stack->top == -1){

        printf ("\n The stack is full! \n"); 
        return -1;  

    }

    int returnable = stack->data [stack->top]; 

    stack->top--;

    return returnable; 


}

int main(){

    S* x = create_stack (10); 

    push (x, 10); 
    push (x, 20); 


    print_stack (x); 

    extract (x); 

    print_stack (x); 

    free_stack (x); 


}