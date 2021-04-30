#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void linkedListTraversal(struct node* ptr){
    while (ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//case 1
struct node* insertAtFirst(struct node* head, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

//case 2
struct node* insertAtIndex(struct node* head, int data, int index){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while(p -> next != NULL){
        p = p -> next;
        i++;
    }

    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

//case 3
struct node* insertAtEnd(struct node* head, int data){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> data = data;
    struct node* p =head;
    while(p -> next != NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

//case 4
struct node* insertAfterNode(struct node* head, struct node* prevNode, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
    return head;
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
    fourth = (struct node*) malloc(sizeof(struct node));

    //Link first and second nodes
    head -> data = 7;
    head -> next = second;

    //Link second and third node
    second -> data = 11;
    second -> next = third;

    //Link third and fourth node
    third -> data = 41;
    third -> next = fourth;

    //Terminate the list at the third node
    fourth -> data = 66;
    fourth -> next = NULL;

    printf("Linked list before the Insertion \n");
    linkedListTraversal(head);

    //head = insertAtFirst(head,56);
    //head = insertAtIndex(head,56,1);
    //head = insertAtEnd(head,56);
    head = insertAfterNode(head,third,45);
    printf("\nLinked list after the Insertion\n");
    linkedListTraversal(head);
    return 0;
}