#include<stdio.h>
#include<stdlib.h>

void solve(long long int* arr,long long int* stack,long long int* res,long long int n);

int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int stack[2*n];
    long long int res[n];
    solve(arr,stack,res,n);
    for(int i=0;i<n;i++){
        printf("%lld ",res[i]);
    }
    printf("\n");
}