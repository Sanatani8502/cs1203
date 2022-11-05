#include<stdio.h>
#include<stdlib.h>

struct avlnode{
    int val; 
    struct avlnode* left; 
    struct avlnode* right; 
    int height; 
}; 

int max (int y, int z){
    return y>z?y:z; 
}

struct avlnode* makenode(int val){
    struct avlnode* node = (struct avlnode*) malloc(sizeof(struct avlnode)); 
    node->val = val; 
    node->left = NULL; 
    node->right = NULL; 
    node->height = 1; 

    return node; 
}

int findbalance(struct avlnode* x){
    if(x == NULL){
        return 0; 
    }
    return findheight(x->left) - findheight(x->right); 
}

int findheight(struct avlnode* ptr){

    if(ptr == NULL){
        return 0; 
        return ptr->height; 
    }
}

struct avlnode* rightrotate(struct avlnode* a){
    struct avlnode* b = a->left; 
    struct avlnode* c = a->right; 

    b->right = a; 
    a->left = c; 

    a->height = max(findheight(a->right), findheight(a->left))+1; //Updating the heights 
    b->height = max(findheight(b->right), findheight(b->left))+1; 

    return b; 
}

struct avlnode* leftrotate(struct avlnode* b){
    struct avlnode* a = b->right; 
    struct avlnode* c = a->right; 

    a->left = b; 
    b->right = c;  

    a->height = max(findheight(a->right), findheight(a->left))+1; //Updating the heights 
    b->height = max(findheight(b->right), findheight(b->left))+1;  

    return a; 
}

struct avlnode* insert(struct avlnode* targetnode, int val){
    if (targetnode == NULL){
        return(makenode(val)); 
    }
    if(val < targetnode->val){
        targetnode->left = insert(targetnode->left, val); 
    }
    else if (val > targetnode->val){
        targetnode->right = insert(targetnode->right, val); 
        return targetnode; 
    }
    targetnode->height = 1+max(findheight(targetnode->left), findheight(targetnode->right)); // Updating the height of the node// 
    int balance = findbalance(targetnode); 

    if (balance>1 && val < targetnode->left->val){    //Left left case// 
        return rightrotate(targetnode); 
    }

    if (balance<-1 && val>targetnode->right->val){   //Right right case// 
        return leftrotate(targetnode); 
    }

    if (balance>1 && val>targetnode->left->val){     //Left right case// 

        return rightrotate(targetnode); 

    }

    if (balance<-1 && val<targetnode->right->val){            //Right left case// 
        targetnode->right = rightrotate(targetnode->right); 
        return leftrotate(targetnode); 
    }

}

void printavl(struct avlnode* root){
    if (root != NULL){
        printf(" %d ", root->val); 
        printavl(root->left); 
        printavl(root->right); 
    }

}

int main(){

    struct avlnode* root = NULL; 
    root = insert (root, 30); 
    root = insert (root, 25); 
    root = insert (root, 15); 
    root = insert (root, 54); 
    root = insert (root, 103); 
    root = insert (root, -9); 

    printavl(root); 



}