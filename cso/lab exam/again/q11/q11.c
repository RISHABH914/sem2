#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void q11(long long int n,long long int* arr,long long int* temp,long long int* res);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int stack[n];
    long long int res[n];
    q11(n,arr,stack,res);
    for(int i=0;i<n;i++){
        printf("%lld ",res[i]);
    }
return 0;
}