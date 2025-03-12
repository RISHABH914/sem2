#include<stdio.h>

long long int find(int*arr,int size);
int main(){
   long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",n);
return 0;
}