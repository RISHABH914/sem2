#include <stdio.h>

void solve(long long int *arr, long long int *res, long long int size);

int main()
{
   long long int n;
    scanf("%lld", &n);
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

//basic logic will be first count number of 0 in the array
// if the count is >=2 then all answer will be 0
// else compute the product of all the number except 0 and then do something something