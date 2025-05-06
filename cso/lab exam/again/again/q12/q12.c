#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q12(long n,long d);
int main(){
    long n,d;
    scanf("%ld %ld",&n,&d);
    if(q12(n,d)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}