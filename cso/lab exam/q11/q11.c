#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void q11(long long int n,long long int* arr,long long int* res,long long int* stack);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long int res[n];
    long long int stack[n];
    q11(n,arr,res,stack);
    for(int i=0;i<n;i++){
        printf("%lld ",res[i]);
    }
    printf("\n");
return 0;
}