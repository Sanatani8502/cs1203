#include<stdio.h>
#include<stdlib.h>

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selection_sort(int unsorted_nums[], int length) {
    for (int i = 0; i < length; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (unsorted_nums[j] < unsorted_nums[min]) {
                min = j;
            }
        }
        // swap with min with i
        int temp = unsorted_nums[i];
        unsorted_nums[i] = unsorted_nums[min];
        unsorted_nums[min] = temp;
    }
}


int main(void) {
    int size;
    printf("Size of the array ");
    scanf("%d", &size);

    int unsorted_array[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &unsorted_array[i]);
    }

    printf("The unsorted array is: ");
    print_array(unsorted_array, size); 
    
    selection_sort(unsorted_array, size); 

    printf("The sorted array is: ");
    print_array(unsorted_array, size); 
}