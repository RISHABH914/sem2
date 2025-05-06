#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q5(long n,long* arr,long* temp);
int main(){
    long n;
    scanf("%ld",&n);
    long arr[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&arr[i]);
    }
    long temp[n];
    int size=q5(n,arr,temp);
    for(int i=0;i<size;i++){
        printf("%ld ",temp[i]);
    }
return 0;
}