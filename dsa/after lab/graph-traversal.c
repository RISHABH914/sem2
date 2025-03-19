#include<stdio.h>
#include<stdlib.h>
//#define int long long

void solve(int** arr,int* res,int* currsize,int index,int* vis,int n){
    if(index>=n){
        return;
    }
    if(!vis[index]){
    vis[index]=1;
    }else{
        return;
    }
    for(int i=1;i<n;i++){
        if(index==i){
            continue;
        }
        if(!vis[i]){
        if(arr[index][i]==1){
            res[*currsize]=i;
            (*currsize)++;
            solve(arr,res,currsize,i,vis,n);
        }
        }
    }
}

signed cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}
signed main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int **arr=(int**)malloc((n+1)*sizeof(int*));
    for(int i=0;i<n+1;i++){
        arr[i]=(int*)malloc((n+1)*sizeof(int));
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l;
        scanf("%d",&l);
        int *res=(int*)malloc((n+1)*sizeof(int));
        res[0]=l;
        int currsize=1;
        int* vis=(int*)malloc((n+1)*sizeof(int));
        for(int i=0;i<n+1;i++){
            vis[i]=0;
        }
        solve(arr,res,&currsize,l,vis,n+1);
        qsort(res,currsize,sizeof(int),cmp);
        for(int i=0;i<currsize;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
        free(res);
        free(vis);

    }
}