#include <stdio.h>
#define SIZE 3
int items[SIZE];
int front = -1,rear = -1;

int overflow(){
    if ((front == (rear+1)%SIZE) || (front = 0 && rear == SIZE-1)) return 1;
}
int underflow(){
    if (front == -1){
        return 1;
    }return 0;
}
void enqueue(int element){
    if (overflow()) printf("Queue is full\n");
    else{
        if (front == -1){
            front = 0;
            rear = 0;
        } 
        rear = (rear+1)%SIZE;
        items[rear] = element;
        printf("Inserted %d",element);
    }
}
void dequeue(){
    int element;
    if (underflow()) printf("Queue is empty\n");
    else{
        element = items[front];
        if (front == rear){
            front = rear = -1;
        }else{
            front = (front+1)%SIZE;
        }
    }
    printf("Deleted element = %d",element);
}
void display(){
    int i;
    if (underflow()){
        printf("Queue empty");
    }else{
        printf("front = %d",front);
        printf("Items = ");
        for (i = front ; i != rear; i = (i+1)%SIZE){
            printf("%d ",items[i]);
        }
        printf("%d",items[i]);
        printf("\nRear = %d\n",rear);
    }

}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    enqueue(4);
    dequeue();
    display();
    return 0;
}