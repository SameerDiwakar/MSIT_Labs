#include <stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int high, int low){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high ;j++){
        if (arr[j] > pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void qs(int arr[],int low, int high){
    if (low < high){
        int pi = partition(arr,high,low);
        qs(arr,pi-1,low);
        qs(arr,high,pi+1);
    }
}
