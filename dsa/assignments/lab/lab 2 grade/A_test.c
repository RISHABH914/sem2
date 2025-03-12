#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
int main(){
    int t;
    scanf("%d",&t);
while(t--){
    int n,target;
    scanf("%d %d",&n,&target);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   // qsort(arr,n,sizeof(int),cmp);
   int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
}
return 0;
}