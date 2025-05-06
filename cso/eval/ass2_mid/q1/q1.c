#include<stdio.h>
#include<stdlib.h>

long long int solve(long long int* arr,long long int* sum,int n);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int sum[n];
    printf("%lld\n",solve(arr,sum,n));

}