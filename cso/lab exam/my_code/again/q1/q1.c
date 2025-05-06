#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void q1(long long int n,long long int* arr);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    q1(n,arr);
    for(int i=0;i<n;i++){
        printf("%lld ",arr[i]);
    }
    
return 0;
}