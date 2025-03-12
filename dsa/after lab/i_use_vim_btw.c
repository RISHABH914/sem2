#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct stack{
    int top;
    char* arr;

}st;

void push(st* root,char data){
    root->top++;
    root->arr[root->top]=data;
}
void pop(st* root){
    if(root->top<0){return;}
    root->top--;
}

char top(st* root){
    
    return root->arr[root->top];
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,m;
        scanf("%d %d",&n,&m);
        char arr1[n+1];
        char arr2[m+1];
        st* st1=(st*)malloc(sizeof(st));
        st1->top=-1;
        st1->arr=(char*)malloc((n+1)*sizeof(char));
        st* st2=(st*)malloc(sizeof(st));
        st2->top=-1;
        st2->arr=(char*)malloc((m+1)*sizeof(char));
        scanf("%s",arr1);
        scanf("%s",arr2);
        for(int i=0;i<n;i++){
            if(arr1[i]!='x'){
            push(st1,arr1[i]);
            }else{
                if(st1->top>=0){
                    pop(st1);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(arr2[i]!='d'){
            push(st2,arr2[i]);
            }else{
                if(st2->top>=0){
                    pop(st2);
                }
            }
        }
        if(st1->top<0 && st2->top>0){
            printf("no\n");
            continue;
        }
        if(st2->top<0 && st1->top>0){
            printf("no\n");
            continue;
        }
        if(st1->top<0 && st2->top<0){
            printf("yes\n");
            continue;
        }
        int fl=0;
        while(st1->top>=0 && st2->top>=0){
            if(top(st1)!=top(st2)){
                printf("no\n");
                fl=1;
                break;
            }
            pop(st1);
            pop(st2);
        }
        if(fl==1){
            continue;
        }
        if(st1->top>=0 || st2->top>=0){
            printf("no\n");
            continue;
        }

        printf("yes\n");

    }
return 0;
}