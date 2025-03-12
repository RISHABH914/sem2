#include<stdio.h>

int solve(char* s,long long int n);
int main(){
    long long int n;
    scanf("%lld",&n);
    char s[n];
    scanf("%s",s);
    printf("%d\n",solve(s,n));
return 0;
}