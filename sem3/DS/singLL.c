// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insert(struct Node *head,int element){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    struct Node *temp = head;
    if (head == NULL) return newNode;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct Node* del(struct Node* head){
    if (head == NULL) return NULL;
    if (head->next == NULL){
        free(head);
        return NULL;
    }
    struct Node*temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
void printLL(struct Node *head){
    struct Node*temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node*head  = NULL;
    head = insert(head,98);
    printf(" ");
    head = insert(head,5);
    head = insert(head,10);
    printf("List before deletion\n");
    printLL(head);
    head = del(head);
    printf("List after deletion\n");
    printLL(head);
    return 0;
}