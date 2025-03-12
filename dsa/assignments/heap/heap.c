#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void sift_up(int* arr,int size){
    int child=(size-1);
    while(child!=0){
        int parent=(child-1)/2;
        if(arr[parent]>arr[child]){
            arr[child]=arr[parent]+arr[child]-(arr[parent]=arr[child]);
            child=parent;
        }else{
            break;
        }
    }
}
void insert(int* arr,int *size,int data){
    arr[*size]=data;
    (*size)++;
    sift_up(arr,*size);
    
}

void heapify(int *arr, int n, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        arr[index]=arr[index]+arr[smallest]-(arr[smallest]=arr[index]);
        heapify(arr, n, smallest);
    }
}

void delete(int* arr,int *size){
    arr[0]=arr[*size -1];
    (*size)--;
    heapify(arr,*size,0);
}

int main(){
    int t;
    scanf("%d",&t);
    int arr[t];
    int size=0;
    while(t--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int data;
            scanf("%d",&data);
            insert(arr,&size,data);
        }else if(op==2){
            delete(arr,&size);
        }else {
            printf("%d\n",arr[0]);
        }
    }
return 0;
}