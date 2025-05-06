#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int q5(long long int n,long long int* arr,long long int* res);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int res[n];
    long long int size=q5(n,arr,res);
    for(int i=0;i<size;i++){
        printf("%lld ",res[i]);
    }
return 0;
}