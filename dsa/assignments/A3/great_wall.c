#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    int start;
    int end;
    int height;
}node;

int cmp(const void* a,const void* b){
    node temp1=*(node*)a;
    node temp2=*(node*)b;
    if(temp1.start!=temp2.start){
    return temp1.start - temp2.start;
    }
    if(temp2.height==temp1.height){
        if((temp2.end<temp2.start)){
            return -1;
        }else{
            return 1;
        }
    }
    return temp2.height-temp1.height;
}

void sift_up(node* arr,int size){
    int child=(size-1);
    while(child!=0){
        int parent=(child-1)/2;
        if(arr[parent].height<arr[child].height){
            node temp=arr[parent];
            arr[parent]=arr[child];
            arr[child]=temp;
            child=parent;
        }else{
            break;
        }
    }
}
void insert(node* arr,int *size,node data){
    arr[*size]=data;
    (*size)++;
    sift_up(arr,*size);
    
}

void heapify(node *arr, int n, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left].height > arr[smallest].height) {
        smallest = left;
    }
    if (right < n && arr[right].height > arr[smallest].height) {
        smallest = right;
    }

    if (smallest != index) {
        node temp=arr[smallest];
            arr[smallest]=arr[index];
            arr[index]=temp;
        heapify(arr, n, smallest);
    }
}

void delete(node* arr,int *size){
    arr[0]=arr[*size -1];
    (*size)--;
    heapify(arr,*size,0);
}

void merge(node arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    node temp1[n1], temp2[n2];

    for (int i = 0; i < n1; i++)
        temp1[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        temp2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (temp1[i].start < temp2[j].start) {
            arr[k] = temp1[i];
            i++;
        } 
        else if (temp1[i].start == temp2[j].start) {
            if (temp1[i].height > temp2[j].height) {
                arr[k] = temp1[i];
                i++;
            } 
            else if (temp1[i].height < temp2[j].height) {
                arr[k] = temp2[j];
                j++;
            } 
            else {  
                if (temp2[j].end < temp2[j].start) {  
                    arr[k] = temp1[i];
                    i++;
                } 
                else {
                    arr[k] = temp2[j];
                    j++;
                }
            }
        } 
        else {  
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}


void mergesort(node arr[],int left,int right){
    if(left>=right){
        return;
    }
    int mid=(right+left)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
int main(){
    int n;
    scanf("%d",&n);
    node arr[2*n];
    for(int i=0;i<n;i++){
            int start;
            int end;
            int height;
            scanf("%d %d %d",&start,&end,&height);
            arr[2*i].start=start,arr[2*i].end=end,arr[2*i].height=height;
            arr[2*i +1].start=end,arr[2*i +1].end=end-1,arr[2*i +1].height=height;
    }
    //qsort(arr,2*n,sizeof(node),cmp);
   mergesort(arr,0,2*n -1);
   /*for(int i=0;i<2*n;i++){
        printf("%d %d %d\n",arr[i].start,arr[i].end,arr[i].height);
    }*/
    node heap[2*n];
    int size=0;
    int last_ending=-1;
    for(int i=0;i<2*n;i++){
        // case for ending data
        if(arr[i].end<arr[i].start){
            if(last_ending!=-1 && arr[i].start==last_ending){
                continue;
            }
                while(size!=0 && heap[0].end<=arr[i].start){
                    delete(heap,&size);
                }
                if(size!=0){
                    if(heap[0].height<arr[i].height){
                        printf("%d %d\n",arr[i].start,heap[0].height);
                    }
                }else{
                    printf("%d 0 \n",arr[i].start);
                }
                last_ending=arr[i].start;
        }

        //case for starting data
        else if(arr[i].start<arr[i].end){
            while( size!=0 && heap[0].end<arr[i].start){
                delete(heap,&size);
            }
            if(size!=0 && heap[0].height>=arr[i].height){
                insert(heap,&size,arr[i]);
                continue;
            }
            insert(heap,&size,arr[i]);
            printf("%d %d\n",arr[i].start,arr[i].height);
        }
    }
return 0;
}