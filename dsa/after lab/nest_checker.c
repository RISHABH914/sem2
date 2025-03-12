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
    if(root->top<0){
        return -1;
    }
    return root->arr[root->top];
}

int main(){
    st* root=(st*)malloc(sizeof(st));
    root->top=-1;
    root->arr=(char*)malloc(10000*sizeof(char));
    int t;
    scanf("%d",&t);
    while(t--){
        char arr[10000];
        scanf("%s",arr);
        int n=strlen(arr);
    int k=0;
        int fl=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='(' || arr[i]=='[' || arr[i]=='{'){
                push(root,arr[i]);
                k=1;
            }else if(arr[i]==')'){
                if(top(root)!='('){
                    fl=1;
                    break;
                }else{
                    pop(root);
                }
            }else if(arr[i]==']'){
                if(top(root)!='['){
                    fl=1;
                    break;
                }else{
                    pop(root);
                }
            }else if(arr[i]=='}'){
                if(top(root)!='{'){
                    fl=1;
                    break;
                }else{
                    pop(root);
                }
            }
        }
        if(root->top!=-1){
            fl=1;
        }
        if(fl==1 || k==0){
            int left=0;
            int right=n-1;
            int lf=0;
            while(left<right){
                if(arr[left]!=arr[right]){
                lf=1;
                    break;
                }
                left++;
                right--;
            }
            if(lf==1){
                printf("-1\n");
            }else{
                printf("Palindromic\n");
            }
        }else{
            printf("Balanced\n");
        }
    }

return 0;
}