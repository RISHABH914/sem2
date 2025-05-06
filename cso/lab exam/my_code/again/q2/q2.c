#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q2(long n,long* temp);
int main(){
    long n;
    scanf("%ld",&n);
    long temp[21];
    if(q2(n,temp)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
return 0;
}