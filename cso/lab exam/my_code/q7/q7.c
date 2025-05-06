#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int q7(long long int n);
int main(){
    long long int n;
    scanf("%lld",&n);
    if(q7(n)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}