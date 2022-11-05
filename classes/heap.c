#include <stdio.h>
#include <stdlib.h>

struct MinHeapqueue {
    int *numbers;
    int max_size;
    int current_length;
};

int get_parent(int index) {
    return (index - 1) / 2;
}

int get_left_child(int index) {
    return (2 * index) + 1;
}

int get_right_child(int index) {
    return (2 * index) + 2;
}

//Minimum element of the min heap will be the parent 
int get_min_child(struct MinHeapqueue* x) {
    return x->numbers[0];
}

struct MinHeapqueue* insert(struct MinHeapqueue* x, int value) {
    if (x->current_length == x->max_size) {
        printf("Heap is full. Cannot insert %d", value);
        return x; 
    }
    x->numbers[x->current_length] = value;
    x->current_length++;
    int current_index = x->current_length - 1;
    int parent_index = get_parent(current_index);
    while (parent_index >= 0 && x->numbers[parent_index] > x->numbers[current_index]) {
        int temp = x->numbers[parent_index];
        x->numbers[parent_index] = x->numbers[current_index];
        x->numbers[current_index] = temp;
        current_index = parent_index;
        parent_index = get_parent(current_index);
    }
    return x;
}

int main(){

}