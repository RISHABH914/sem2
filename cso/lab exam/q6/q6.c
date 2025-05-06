#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int q6(long long int n,long long int* arr);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    if(q6(n,arr)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}