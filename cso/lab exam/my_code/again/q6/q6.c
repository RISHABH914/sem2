#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q6(long n,long* arr);
int main(){
    long n;
    scanf("%ld",&n);
    long arr[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&arr[i]);
    }
    if(q6(n,arr)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}