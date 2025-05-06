#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int q4(long long int size,long long int arr[size][]);
int main(){
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    long long int arr[n][m];
    long long int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%lld",&arr[i][j]);
            cnt++;
        }
    }

    printf("%lld\n",q4(n*m,&arr[0][0]));
return 0;
}