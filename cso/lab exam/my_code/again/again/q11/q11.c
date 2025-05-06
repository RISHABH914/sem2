#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q11(long* arr,long start,long end,long target);
int main(){
    long n;
    scanf("%ld",&n);
    long arr[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&arr[i]);
    }
    long target;
    scanf("%ld",&target);
    printf("%ld",q11(arr,0,n-1,target));
return 0;
}