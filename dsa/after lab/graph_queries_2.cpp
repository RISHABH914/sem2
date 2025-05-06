#include <iostream>
#include<cmath>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    vector<unordered_map<int,int>> graph(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int start=-1;
        int end=-1;
        for(int j=0;j<n;j++){
            if(arr[j][i]==-1){
                start=j;
            }else if(arr[j][i]==1){
                end=j;
            }
        }
        if (start != -1 && end != -1) {  // Valid connection
            graph[start][end] = 1;
            graph[end][start] = 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int res=(i!=j?(graph[i].find(j)!=graph[i].end()?(-1):(0)):(graph[i].size()));
            cout<<res<<" ";
    }
    cout<<endl;
}

}