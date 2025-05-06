#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int q2(long long int n,long long int* temp);
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[25];
    if(q2(n,arr)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}