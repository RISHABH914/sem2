#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pp;
int dijkstra(vector<vector<pair<int,int>>>& graph,int n){
    vector<int> dist(2*n,LONG_LONG_MAX);
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    dist[0]=0;
    pq.push({dist[0],0});
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        if(dist[node.second]<node.first){
            continue;
        }
        for(auto it:graph[node.second]){
            if(dist[it.first]>dist[node.second]+it.second){
                dist[it.first]=dist[node.second]+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    return dist[n-1];
}
signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> graph(2*n);
        for(int i=0;i<m;i++){
            int a,b,wt;
            cin>>a>>b>>wt;
            graph[a].push_back({b+n,wt});
            graph[a+n].push_back({b,wt});
            graph[b].push_back({a+n,wt});
            graph[b+n].push_back({a,wt});
        }
        int res=dijkstra(graph,n);
        if(res==LONG_LONG_MAX){
            cout<<"-1"<<endl;
        }else{
            cout<<res<<endl;
        }
    }

}