#include <stdio.h>
#include <stdlib.h> 


void sift_down(int* a, int start); 

void printarray (int* a, int size){
    for (int i = 0; i<size; i++){
        printf(" %d ", a[i]);  
    }
    printf("\n"); 
}

int get_parent (int index){

    int parent; 
    parent = (index-1)/2;  

    return parent; 

} 

int getleftchild (int index){   

    int left_child = (2*index) + 1; 

    return left_child; 

}

int getrightchild (int index){

    int right_child = 0; 

    right_child = (2*index) + 2; 

    return right_child; 

}

void swap (int* x, int index1, int index2){

    int temp = x[index1]; 
    x[index1] = x[index2]; 
    x[index2] = temp; 

}

int find_larger (int* a, int index1, int index2){

    if (a[index1] > a[index2]){
        return index1; 
    }

    else if (a[index2] > a[index1]){
        return index2; 
    }

    else {

        return index1; 

    }
    
    //return a[index1] > index2 ? index1 : index2;
}

void sift_down(int* a, int start){ 

    int left = getleftchild (start); 
    int right = getrightchild (start);

    // if (start == 0){

    //     return; 

    // } 

    // else
    
    if (a[start] < a[left] || a[start] < a[right]){
        int swappy = find_larger (a, left, right); 
        swap(a, swappy, start); 
    }

    // put in a condition to check if start was swapped with it's children
    // call the heapify function everytime it's swapped with Parent(start)
    // Recursion should look like:
        // if start < children : 
            // swap
            // heapify(parent(start))
        // else : return

    start = get_parent (start); // segfaults

    while (start > 0){ 
 
        sift_down (a, start); 

    }

}



int main(){

    int arr2[] = {11,20,17,8,10,9,6};  

    printarray (arr2,7); 

    int begin = 2; 

    sift_down (arr2, begin);

    printarray (arr2,7);
}