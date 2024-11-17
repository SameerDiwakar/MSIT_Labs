// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Queue{
    struct Node* front,*rear;
};
void initQueue(struct Queue *q){
    q->front = NULL;
    q->rear = NULL;
}
int isEmpty(struct Queue *q){
    return q->front == NULL;
}

void Enqueue(struct Queue *q, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next =NULL;
    if (q->rear == NULL){
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
void dequeue(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
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