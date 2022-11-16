#include <stdio.h> 
#include <stdlib.h> 


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

int get_sibling (int index){

    int parent = get_parent (index); 

    int child1 = getleftchild (parent); 
    int child2 = getrightchild (parent); 

    

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
    
}

void heapify(int* a, int size, int index){ //Bottom up//

    int left = getleftchild (index);
    int right = getrightchild (index);
    int swappable = index;  

    if (left < size && a[left] > a[index]){ 

        swappable = left; 

    } 

    if (right < size && a[right] > a[index]){

        swappable = right; 

    }

    if (swappable != index){ 

        swap (a, swappable, index); 

        heapify (a, size, swappable); 

    }


}   


int main(){

    int arr2[] = {20,30,25,10,5,29,3,70};    

    int size = 6;  

    printarray (arr2, size); 

    for (int i = (size-1)/2; i >= 0; i--){

        heapify (arr2, size, i); 

    }

    printarray (arr2, size); 

}