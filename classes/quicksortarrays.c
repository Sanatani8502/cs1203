#include<stdio.h>
#include<stdlib.h>

void printarray(int *arr, int size); 
void quicksort(int arr[], int start, int stop); 
int partition(int arr[], int start, int stop);

void printarray(int *arr, int n){
    for (int i=0; i<n; i++){
        printf("\n %d \n", arr[i]); 
    }
} 

void quicksort(int arr[], int start, int stop){
    int p; //Partitions the array into larger and greater subarray about a pivot

    if(start<stop){
        p = partition(arr,start, stop);
        quicksort(arr, start, p-1); //Quicksorting lesser subarray
        quicksort(arr, p+1, stop); //Quicksorting greater subarray
    } 
}

int partition(int arr[], int start, int stop){

    int pivot=arr[start];  //Choosing first array element as pivot 
    int i= start+1; 
    int j=stop; 
    int temp; 

    do{ //Do this entire procedure as long as i<j 
        while(arr[i]<=pivot){
            i++; 
        }
    
        while(arr[j]>pivot){
            j--; 
        }

        if(i<j){        //Swap the values at ith and jth index  
            temp=arr[i]; 
            arr[i]=arr[j]; 
            arr[j]=temp; 
        }
    }while(i<j); 

    //Finally swap arr[i] and arr[j] to put pivot at correct position
    temp=arr[start]; 
    arr[start]=arr[j]; 
    arr[j]=temp; 
    return j; 

}

int main(){

    int arr[]={1,4,20,40,30,12,14,18,18,10}; 
    int size=sizeof(arr)/sizeof(int); 
    printarray(arr,size);
    quicksort(arr,0,size-1);  

    printf("After sorting \n"); 

    printarray(arr,size); 


}