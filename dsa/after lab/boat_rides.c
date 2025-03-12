#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void* a,const void* b){
    return *(long long int*)a - *(long long int*)b;
}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    qsort(arr,n,sizeof(long long int),cmp);
    int left=0;
    int right=n-1;
    int cnt=0;
    while(left<right){
        if(arr[right]+arr[left]<=x){
            cnt++;
            left++;
            right--;
        }else if(arr[right]+arr[left]>x){
            right--;
            cnt++;
        }
    }
    if(left==right){
        cnt++;
    }
    printf("%d\n",cnt);
return 0;
}