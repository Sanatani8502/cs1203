#include<stdio.h>
#include<stdlib.h> 

void insertionsort(int* arr, int n); //sorts array from smallest to greatest  
void printarray(int *arr, int n); 

void printarray(int *arr, int n){
    for (int i=0; i<n; i++){
        printf("\n %d \n", arr[i]); 
    }
}

void insertionsort(int* arr, int n){
    for(int i=1; i<=n-1; i++){   //Iterate through entire array
        int new_val=arr[i];  //New value to be inserted into sorted array at correct position 
        int j=i-1; 

        while(arr[j]>new_val && j>=0){  
            arr[j+1]=arr[j]; 
            j=j-1; 
        }
        arr[j+1]=new_val; //If j becomes negative, put new_val at the position before it
    }
}

int main(){

int arr[]={30,40,10,15,60,90,5}; 
int n=7; 

printarray(arr, n); 
printf("AFTER SORTING:"); 
insertionsort(arr, n); 
printarray(arr, n); 
}