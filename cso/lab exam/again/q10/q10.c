#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q10(long long int n,char* s,long long int* stack);
int main(){
    long long int n;
    scanf("%lld",&n);
    char s[n];
    scanf("%s",s);
    long long int temp[n];
    if(q10(n,s,temp)){
        printf("BALANCED\n");
    }else{
        printf("NOT BALANCED\n");
    }
return 0;
}