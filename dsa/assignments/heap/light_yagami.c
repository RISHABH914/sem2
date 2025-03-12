
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] > arr[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&arr[index], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int pop(int *arr, int *length) {
    if (*length <= 0) return 0;  // Edge case handling
    int ret = arr[0];
    arr[0] = arr[(*length) - 1];
    (*length)--;
    heapify(arr, *length, 0);
    return ret;
}

void sift_up(int *arr, int index) {
    if (index <= 0) return;
    int parent = (index - 1) / 2;
    if (arr[parent] < arr[index]) {
        swap(&arr[parent], &arr[index]);
        sift_up(arr, parent);
    }
}

void insert(int *arr, int *index, int data) {
    arr[*index] = data;
    (*index)++;
    sift_up(arr, (*index) - 1);
}

int main() {
    int n,x;
    scanf("%d %d",&n,&x);
    int arr[n];
    int index=0;
    for(int i=0;i<n;i++){
            int data;
            scanf("%d",&data);
            insert(arr,&index,data);
    }
    int used=0;
    while(used<x){
        int temp=arr[0];
        pop(arr,&n);
        temp=temp/2;
        insert(arr,&n,temp);
        used++;
    }
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("%lld\n",sum);

}