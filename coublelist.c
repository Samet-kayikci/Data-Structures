#include <stdio.h>
#include <stdlib.h>

    struct list{
        int data;
        struct list *next;
        struct list *back;
    };
    typedef struct list node;

    node *root=NULL;
    node *tail=NULL;
    node *iter;
    void add(int input){
        if(root == NULL){
            node *addnode = (node *)malloc(sizeof(node));;
            addnode -> data =input;
            addnode -> next = NULL;
            addnode -> back = NULL;
            root = addnode;
            tail = root;
            iter = root;
        }
        else if(root != NULL){
            node *addnode = (node *)malloc(sizeof(node));
            addnode -> data = input;
            iter -> next = addnode;
            addnode -> back = iter;
            addnode -> next = NULL;
            tail = addnode;
            iter = iter -> next;
        }


    }

    void head_add(int input){
        node *head_node = (node *)malloc(sizeof(node));
        head_node -> data = input;
        root -> back = head_node;
        head_node -> next = root;
        root = head_node;
        root -> back = NULL;
        head_node=NULL;
    }

    
    int main(){
        add(10);
        add(15);
        add(9);
        add(2);
        head_add(1);
        head_add(100);
        node *loop= root;
        while(loop != NULL){

            printf("%d ",loop -> data);
            loop = loop -> next;
        }

        printf("\n");
        printf("%d",root -> next -> next -> next -> back -> data);
        return 0;
    }