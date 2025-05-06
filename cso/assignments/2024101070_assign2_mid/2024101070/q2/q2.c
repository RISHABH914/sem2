    #include<stdio.h>
    #include<stdlib.h>

    long long solve(long long n,long long r);
    //{
    //     long temp=1;
    //     return n/r * solve(n-1,r-1);

    // }
    int main(){
        long long int n,r;
        scanf("%lld %lld",&n,&r);
        printf("%lld\n",solve(n,r));

    }