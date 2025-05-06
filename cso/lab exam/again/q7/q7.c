#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q7(long n);
int main(){
    long n;
    scanf("%ld",&n);
    if(q7(n)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}