#include<string.h>
int solve(char* s,long long int n);
int main(){
    char s[1000000];
    scanf("%s",s);
    printf("%d\n",solve(s,strlen(s)));
return 0;
}