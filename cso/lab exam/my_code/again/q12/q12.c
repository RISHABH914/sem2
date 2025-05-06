#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int q12(long long int n,long long int d);
int main(){
    long long int n,d;
    scanf("%lld %lld",&n,&d);
    if(q12(n,d)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}