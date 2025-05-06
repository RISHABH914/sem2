#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define int long long
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int result(int* arr,int start,int end,int x){
    if(end<start){
        return -1;
    }

    for(int i=start;i<=end;i++){
        if(arr[i]<=(x/(end-start+1))){
            int temp1=result(arr,start,i-1,x);
            int temp2=result(arr,i+1,end,x);
            return max(temp1,temp2);
        }
    }
    return (end-start+1);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,x;
        scanf("%lld %lld",&n,&x);
        int arr[n];
        for(int i=0;i<n;i++){
           scanf("%lld",&arr[i]);
        }
        printf("%lld\n",result(arr,0,n-1,x));
    }

}