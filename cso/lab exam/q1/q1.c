#include<stdio.h>
#include<stdlib.h>
void q1(long long int n,long long int* res);

int main(){
    long long int n;
    scanf("%lld",&n);
    long long int res[n];
    q1(n,res);
    for(int i=0;i<n;i++){
        printf("%lld ",res[i]);
    }
return 0;
}