// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4
int top = -1, arr[SIZE];
void push();
void pop();
void show();
int main() {
    int choice;
    while (1){
        printf("\nPerform operation on the stack: \n1. Push \n2. Pop \n3. Show \n4. End");
        printf("Enter choice nigga");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(){
    int num;
    if(top == SIZE - 1){
        printf("Overflow!!\n");
        return;
    }
    printf("Enter number to push: ");
    scanf("%d",&num);
    arr[++top] = num;
}

void pop(){
    if(top == -1){
        printf("Underflow!\n");
        return;
    }
    printf("Popped element  %d\n", arr[top--]);
}

void show(){
    int i;
    if(top == -1){
        printf("Stack is empty,underflow\n");
        return;
    }
    printf("Elements present in the stack: ");
    for(i = 0; i <= top; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}