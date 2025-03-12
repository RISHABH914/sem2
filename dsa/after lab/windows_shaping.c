#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
typedef struct stack{
    int* arr;
    int top;
}stack;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int *stack=(int*)malloc(n*sizeof(int));
        int top=0;
        int pre[n];
        for(int i=0;i<n;i++){
            while(top>0 && arr[stack[top-1]]>=arr[i]){
                top--;
            }
            if(top==0){
                pre[i]=-1;
            }else{
                pre[i]=stack[top-1];
            }

            stack[top]=i;
            top++;
        }
        top=0;
        int suf[n];
        for(int i=n-1;i>=0;i--){
            while(top>0 && arr[stack[top-1]]>=arr[i]){
                top--;
            }
            if(top==0){
                suf[i]=n;
            }else{
                suf[i]=stack[top-1];
            }
            stack[top]=i;
            top++;
        }
        int res[n+1];
        for(int i=0;i<=n;i++){
            res[i]=INT_MIN;
        }
        for(int i=0;i<n;i++){
            int size=suf[i]-pre[i]-1;
            res[size]=max(res[size],arr[i]);
        }

        for(int i=n-1;i>=1;i--){
            res[i]=max(res[i],res[i+1]);
        }

        for(int i=1;i<=n;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
return 0;
}