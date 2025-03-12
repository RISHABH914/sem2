#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
int cmp(const void* a,const void* b){
    const int *rowA = (const int *)a;
    const int *rowB = (const int *)b;
    return rowA[1] - rowB[1]; 
}
int main(){
    int t;
    scanf("%d",&t);
    int arr[t][2];
    for(int i=0;i<t;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        arr[i][0]=a;
        arr[i][1]=b;
    }
    qsort(arr,t,sizeof(arr[0]),cmp);
    
    int prev=arr[0][1];
    int cnt=1;
    int max=1;
    for(int i=0;i<t;i++){
        if(arr[i][0]<prev){
            cnt++;
            if(cnt>max){
                max=cnt;
            }
           // prev=arr[i][1];
        }else{
            cnt=1;
            prev=arr[i][1];
        }
    }
    printf("%d\n",max);
return 0;
}