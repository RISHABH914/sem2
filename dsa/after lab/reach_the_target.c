#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int solve(int n,int x,int y,int target){
    if(n>target){
        return 0;
    }
    if(n==target){
        return 1;
    }
    return (solve(n+x,x,y,target) || (solve(n*y,x,y,target)));
}
int main(){
    int n,x,y,target;
    scanf("%d %d %d %d",&n,&target,&x,&y);
    int fl=0;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
    if(solve(t,x,y,target)==1){
        printf("Yes\n");
        fl=1;
        break;
    }
    }
    if(!fl){
        printf("No\n");
    }
return 0;
}