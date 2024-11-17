#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
    int id;
    char name[100];
};

struct Node{
    struct Employee data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int id,const char *name){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data.name, name);
    newNode->data.id = id;
    newNode->prev = NULL;
    newNode->next = NULL;
}
void insertatFront(struct Node **head, int id, const char *name){
    struct Node* newNode = createNode(id, name);
    newNode->next = *head;
    if (*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void deleteatEnd(struct Node **head){
    if (*head == NULL){
        printf("List is empty");
        return;
    }
    struct Node *temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    if (temp->prev!=NULL){
        temp->prev->next = NULL;
    }else{
        *head = NULL;
    }
    free(temp);
}
void printList(struct Node *head){
    struct Node *temp = head;
    while(temp!=NULL){
        printf("%d %s\n", temp->data.id, temp->data.name);
        temp = temp->next;
    }
}

int main(){
    struct Node *head = NULL;
    insertatFront(&head,1,"Ram");
    insertatFront(&head,2,"Shyam");
    printf("List after insertion:\n");
    printList(head);
    deleteatEnd(&head);
    printf("\nList after deletion:\n");
    printList(head);
    while(head!=NULL){
        deleteatEnd(&head);
    }
    return 0;
}