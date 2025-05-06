#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long q4(long n,long** arr);
int main(){
    long n,m;
    scanf("%ld %ld",&n,&m);
    long arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%ld",&arr[i][j]);
        }
    }
    printf("%ld\n",q4(n*m,arr));
return 0;
}