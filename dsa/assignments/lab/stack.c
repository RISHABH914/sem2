#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct stack{
    int* arr;
    int top;
    int size;
}stack;

int top(stack* root){
    return root->arr[(root->top)-1];
}

int isfull(stack* root){
    if(root->top>=root->size){
        root->arr=(int*)realloc(root->arr,(root->size*2)*sizeof(int));
        root->size=(root->size)*2;
        return 1;
    }

    return 0;
}

void push(stack* root,int data){
    isfull(root);
    root->arr[root->top]=data;
    root->top++;
}

void pop(stack* root){
    if(root->top<=0){
        return ;
    }
    root->top--;
}

void print_stack(stack* root){
    while(root->top>0){
       // printf("hello\n");
        printf("%d\n",top(root));
        pop(root);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    stack* root=(stack*)malloc(sizeof(stack));
    root->arr=(int*)malloc(1*sizeof(int));
    root->size=1;
    root->top=0;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        push(root,arr[i]);
    }
    print_stack(root);
    

return 0;
}