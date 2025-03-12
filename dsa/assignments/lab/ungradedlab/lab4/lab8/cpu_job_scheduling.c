#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct pair{
    int first;
    int second;
}pair;

int cmp(const void* a,const void* b){
    pair one=*(pair*)a;
    pair another=*(pair*)b;
    if(one.first>another.first){
        return 1;
    }else if(one.first<another.first){
        return -1;
    }
    else {
        if(one.second<another.second){
            return -1;
        }else{
            return 1;
        }
    }
}
void sift_up(long long int* arr,long long int size){
    long long int child=(size-1);
    while(child!=0){
        long long int parent=(child-1)/2;
        if(arr[parent]>arr[child]){
            arr[child]=arr[parent]+arr[child]-(arr[parent]=arr[child]);
            child=parent;
        }else{
            break;
        }
    }
}
void insert(long long int* arr,long long int *size,long long int data){
    arr[*size]=data;
    (*size)++;
    sift_up(arr,*size);
    
}

void heapify(long long int *arr, long long int n, long long int index) {
    long long int smallest = index;
    long long int left = 2 * index + 1;
    long long int right = 2 * index + 2;

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

void delete(long long int* arr,long long int *size){
    arr[0]=arr[*size -1];
    (*size)--;
    heapify(arr,*size,0);
}

int main(){
   long long int n;
   scanf("%lld",&n);
   long long int start[n];
   long long int end[n];
   pair timing[n];
   for(int i=0;i<n;i++){
    scanf("%lld",&start[i]);
    timing[i].first=start[i];
   }
   for(int i=0;i<n;i++){
    scanf("%lld",&end[i]);
    timing[i].second=end[i];
   }
   qsort(timing,n,sizeof(pair),cmp);
   for(int i=0;i<n;i++){
    start[i]=timing[i].first;
    end[i]=timing[i].second;
   }
   long long int count=0;
   long long int min_heap[n];
   for(int i=0;i<n;i++){
        if(count!=0){
            if(min_heap[0]<start[i]){
                delete(min_heap,&count);
                insert(min_heap,&count,end[i]);
            }else{
            insert(min_heap,&count,end[i]);
            }
        }else{
            insert(min_heap,&count,end[i]);
        }
   }
   printf("%lld\n",count);
return 0;
}

