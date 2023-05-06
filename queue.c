#include <stdio.h>
#include <stdlib.h>

 struct queue{
    int data;
    struct queue *next;
 };
 typedef struct queue node;

 node *root=NULL;

 void add(int input){

    node *newnode = (node *)malloc(sizeof(node));
    node *iter=root;
    if(root == NULL)
    root=newnode;
    else{
    newnode -> data = input;
    newnode -> next = NULL;

    while(iter -> next != NULL)
    iter = iter -> next;

    iter -> next = newnode;
    iter -> data = input;
    }
 }


 int output(){
   if(root == NULL){
      return 0;
   }

  node *outroot = root;

  root = root -> next;
  free(outroot); 
  node *iter = root;
  
      printf("\n\n");
   while(iter -> next != NULL){
      printf("%d ",iter -> data);
      iter = iter -> next;
   }
   return 1;
 }


 int main(){
    root = (node *)malloc(sizeof(node));
    add(3);
    add(2);
    add(6);
    add(1);
    add(4);



    node *iter=root;
    while(iter -> next != NULL){
        printf("%d ",iter -> data);
        iter = iter -> next;
    }

       output();
       output();
       output();
       output();


    return 0;
}