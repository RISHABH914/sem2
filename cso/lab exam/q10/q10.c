#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int q10(long long int n,char* string,long long int* temp);
int main(){
    long long int n;
    scanf("%lld",&n);
    char string[n];
    scanf("%s",string);
    long long int temp[n];
    if(q10(n,string,temp)){
        printf("BALANCED\n");
    }else{
        printf("NOT BALANCED\n");
    }
return 0;
}