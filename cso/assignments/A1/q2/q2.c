#include<stdio.h>
void solve(long long int* arr,long long int* output,long long int size);

int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int res[n];
    solve(arr,res,n);
    for(int i=0;i<n;i++){
        printf("%lld ",res[i]);
    }
return 0;
}