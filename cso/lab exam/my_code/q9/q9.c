#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int q9(long long int target,long long int* arr,long long int start,long long int end);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int target;
    scanf("%lld",&target);
    printf("%lld\n",q9(target,arr,0,n-1));

return 0;
}