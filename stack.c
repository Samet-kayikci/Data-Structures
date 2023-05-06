#include <stdio.h>
#include <stdlib.h>

    struct list{
        int data;
        struct list *next;
    };
    typedef struct list node;

    node *root;
    // push         prepend numbers
 void push(int input){      
    if(root==NULL){
        node *pushnode = (node *)malloc(sizeof(node));
        pushnode -> data=input;
        pushnode -> next= root;
        root = pushnode;
        pushnode = NULL;
    }    
    else{
        node *pushnode = (node *)malloc(sizeof(node));
        pushnode -> data = input;
        pushnode -> next = root;
        root = pushnode;
    }
    
 }

 // pop;

 void pop(){ 
    if(root == NULL)
    return;
    node *newroot = (node *)malloc(sizeof(node));

        newroot = root -> next;
     free(root);
     root=newroot;
    return; 
 }


 void peep(){
    if(root == NULL){
        return;
    }
    node *peeproot = (node *)malloc(sizeof(node));
    peeproot = root;
    printf("\n\n");
 
    printf("peep: %d",peeproot -> data);
    return;
 }


 int main(){
    root= (node *)malloc(sizeof(node));

    push(3);
    push(1);
    push(2);
    push(4);


    node *iter;
    iter=root;
    while(iter -> next!= NULL){
        printf("%d\n",iter -> data);
        iter = iter -> next;
    }

    peep();
    pop();
    peep();
    return 0;
 }