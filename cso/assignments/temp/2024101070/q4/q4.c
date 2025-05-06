#include<stdio.h>

long long int max(long long int* arr,long long int size);


int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    printf("%lld\n",max(arr,n));
return 0;
}