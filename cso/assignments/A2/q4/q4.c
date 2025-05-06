#include<stdio.h>
#include<stdlib.h>

long long int solve(long long int n,long long arr[]);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    printf("%lld\n",solve(n,arr));

}