#include<stdio.h> 
#include<stdlib.h> 

int main(){

    for(float i=0.1; i<=5; i+=0.1){ 
        printf("\n %f \n",i); 
    }
    //The for loop breaks as soon as it reaches 2.7, the next number is not 2.8 but 2.799999//
    
    printf("\n Same thing tried with different values:\n ");
    for(float i=0.2; i<=6; i+=0.2){ 
        printf("\n %f \n",i); 
    }

    //I noticed that it could successfully print values if I used i<=5 but broke down if I used six// 
}

