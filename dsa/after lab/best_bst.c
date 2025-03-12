#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
void solve(int arr[],int left,int right){
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    printf("%d ",arr[mid]);
    solve(arr,left,mid-1);
    solve(arr,mid,right);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    qsort(arr,n,sizeof(int),cmp);
    solve(arr,0,n);
return 0;
}