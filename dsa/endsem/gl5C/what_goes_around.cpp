#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int dfs(vector<vector<int>>& graph,int index,int parent,vector<int>& vis,int start){
    vis[index]=1;
    for(auto it:graph[index]){
        if(it==parent){
            continue;
        }

        if(it==start){
            return 1;
        }
        if(!vis[it]){
            if(dfs(graph,it,index,vis,start)){
                return 1;
            }
        }
    }
    return 0;
}
signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
    vector<int> vis(n+1,0);
   if(dfs(graph,i,-1,vis,i)){
    cout<<"YES"<<endl;
    return 0;
   }
}
    cout<<"NO"<<endl;
}