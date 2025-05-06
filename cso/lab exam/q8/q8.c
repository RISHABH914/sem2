#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void q8(long long int n,long long int* arr,long long int* temp);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    long long int temp[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    q8(n,arr,temp);
    for(int i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
return 0;
}