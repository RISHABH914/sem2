#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;

void bfs(vector<vector<int>>& graph,int* nodes,int* edges,int index,vector<int>& vis){
    if(vis[index]){
        return;
    }
    vis[index]=1;
    (*nodes)++;
    for(auto it:graph[index]){
        (*edges)++;
        if(!vis[it]){
            bfs(graph,nodes,edges,it,vis);
        }
    }
}
signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> vis(n,0);
    int nodes=0;
    int edges=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(graph,&nodes,&edges,i,vis);
            if(nodes!=(edges/2)){
                cout<<"NO"<<endl;
                return 0;
            }
            edges=0;
            nodes=0;
        }
    }
    cout<<"YES"<<endl;


}