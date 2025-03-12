#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// theres no elemetn at root->top
// there is element at root->rear
typedef struct queue{
    int* arr;
    int size;
    int top; //storing the element printed on top
    int rear;
}queue;

void push(queue* root,int data){
    if(root->size <= root->top){
        root->arr=(int*)realloc(root->arr,(root->size*2)*sizeof(int));
        root->size=(root->size)*2;
    }
    root->arr[root->top]=data;
    root->top++;
}

void pop(queue* root){
    if(root->rear>=root->top){
        return;
    }
    root->rear++;
}

int isempty(queue* root){
    if(root->rear>=root->top){
        return 1;
    }
}
// return -1 if there is no element
int top(queue* root){
    if(root->rear<root->top){
    return root->arr[root->rear];
    }else{
        return -1;
    }
}

void print(queue* root){
    for(int i=root->rear;i<root->top;i++){
        printf("%d\n",root->arr[i]);
    }
}
int main(){
    queue* root=(queue*)malloc(sizeof(queue));
    root->arr=(int*)malloc(1*sizeof(int));
    root->size=1;
    root->top=0;
    root->rear=0;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        push(root,arr[i]);
    }
    print(root);
return 0;
}