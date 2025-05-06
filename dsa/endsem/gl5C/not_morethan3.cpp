#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& graph,int n){
    vector<int> dist(n+1,LONG_LONG_MAX);
    vector<pair<int,int>> count(n+1,{0,0});
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[1]=0;
    count[1]={1,0};
    pq.push({dist[1],1});
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        for(auto it:graph[node.second]){
            if(it.first%2==0){
                if(count[node.second].second>2){
                    continue;
                }
            }else if(it.first%2!=0){
                if(count[node.second].first>2){
                    continue;
                }
            }
            if(dist[it.first]>dist[node.second]+it.second){
                count[it.first].first=(count[it.first].first)+(it.first%2);
                count[it.first].second+=(it.first%2 == 0);
                dist[it.first]=dist[node.second]+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    return dist;

}
signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        graph[a].push_back({b,wt});
        graph[b].push_back({a,wt});
    }
    vector<int> res=dijkstra(graph,n);
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }


}