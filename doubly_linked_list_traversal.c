#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void linkedListForward(struct node* ptr){
    while (ptr != NULL){
        printf("Element : %d\n",ptr -> data);
        ptr = ptr -> next;
    }
}

void linkedListBackward(struct node* ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr -> data);
        ptr = ptr -> prev;
    }
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    //Allocate memory for nodes in the linked list in heap
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    //linking nodes
    head -> data = 7;
    head -> prev = NULL;
    head -> next = second;

    second -> data = 11;
    second -> prev = head;
    second -> next = third;

    third -> data = 41;
    third -> prev = second;
    third -> next = fourth;

    fourth -> data = 66;
    fourth -> prev = third;
    fourth -> next = NULL;
    
    printf("Forward Traversal\n");
    linkedListForward(head);
    printf("Backward Traversal\n");
    linkedListBackward(fourth);
    return 0;
}