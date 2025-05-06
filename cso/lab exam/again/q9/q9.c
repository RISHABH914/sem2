#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q9(long* arr,long target,long start,long end);
int main(){
    long n;
    scanf("%ld",&n);
    long arr[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&arr[i]);
    }
    long target;
    scanf("%ld",&target);
    printf("%ld\n",q9(arr,target,0,n-1));
return 0;
}