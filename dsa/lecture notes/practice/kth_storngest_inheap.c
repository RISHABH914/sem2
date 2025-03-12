#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void sift_down(int arr[],int n,int index){
    if(index>=n){
        return ;
    }
    int child1=2*index +1;
    int child2=2*index +2;
    int largest=index;
    if(child1<n && arr[child1]>arr[largest]){
        largest=child1;
    }
    if(child2<n && arr[child2]>arr[largest]){
        largest=child2;
    }
    if(index!=largest){
    arr[index]=arr[largest]+arr[index]-(arr[largest]=arr[index]);
    sift_down(arr,n,largest);
    }
    
}

void sift_up(int arr[],int n,int index){
    int parent=(index-1)/2;
    if(arr[parent]<arr[index]){
        arr[parent]=arr[index]+arr[parent]-(arr[index]=arr[parent]);
        sift_up(arr,n,parent);
    }
}
void heapify(int arr,int n){

}

void insert(int arr[],int data,int* size){
    arr[*size]=data;
    (*size)++;
    sift_up(arr,*size,(*size)-1);
    
}

void delete(int arr[],int* size){
    arr[0]=arr[*size -1];
    (*size)--;
    sift_down(arr,*size,0);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    int res[n];
    int size=0;
    for(int i=0;i<k;i++){
        insert(res,arr[i],&size);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<res[0]){
            delete(res,&size);
        }
    }
    printf("%d\n",res[0]);
    
return 0;
}