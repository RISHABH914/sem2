#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct stack{
    int top;
    int* arr;

}st;

void push(st* root,int data){
    root->top++;
    root->arr[root->top]=data;
}
void pop(st* root){
    if(root->top<0){return;}
    root->top--;
}

int top(st* root){
    if(root->top<0){
        return -1;
    }
    return root->arr[root->top];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        st* root=(st*)malloc(sizeof(st));
        root->arr=(int*)malloc(n*sizeof(int));
        root->top=-1;
        for(int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            while(root->top>=0 && top(root)<t){
                pop(root);
            }
            push(root,t);
        }
        st* temp=(st*)malloc(sizeof(st));
        temp->arr=(int*)malloc(n*sizeof(int));
        temp->top=-1;
        while(root->top>=0){
            push(temp,top(root));
            pop(root);
        }
       while(temp->top>=0){
        printf("%d ",temp->arr[temp->top]);
        pop(temp);

       }
       printf("\n");
    }
return 0;
}