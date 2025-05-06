#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void q8(long n,long* arr);
int main(){
    long n;
    scanf("%ld",&n);
    long arr[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&arr[i]);
    }
    q8(n,arr);
    for(int i=0;i<n;i++){
        printf("%ld ",arr[i]);
    }
return 0;
}