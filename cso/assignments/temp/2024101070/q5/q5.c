#include <stdio.h>

void productExceptSelf(long long int *arr, long long int *res, long long int size);

int main()
{
   long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int res[n];
    productExceptSelf(arr,res,n);
    for(int i=0;i<n;i++){
        printf("%lld ",res[i]);
    }
    return 0;
}