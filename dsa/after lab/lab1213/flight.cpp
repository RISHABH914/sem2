#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;

void dijkstra(vector<vector<pair<int,int>>>& graph,int start,vector<int>& dis){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        if(temp.first > dis[temp.second]){
            continue;
        }
        for(auto it:graph[temp.second]){
            if(dis[it.first]>dis[temp.second]+it.second){
                dis[it.first]=dis[temp.second]+it.second;
                pq.push({dis[it.first],it.first});
            }
        }
    }
}
signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph1(n);
    vector<vector<pair<int,int>>> graph2(n);
    vector<vector<int>> edges(m);
int temp=m;
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        
        a--,b--;
        edges[i].push_back(a);
        edges[i].push_back(b);
        edges[i].push_back(wt);
        graph1[a].push_back({b,wt});
        graph2[b].push_back({a,wt});
    }

    vector<int> dis1(n,LONG_LONG_MAX);
    dis1[0]=0;
    vector<int> dis2(n,LONG_LONG_MAX);
    dis2[n-1]=0;

        dijkstra(graph1,0,dis1);
        dijkstra(graph2,n-1,dis2);
int ans=LONG_LONG_MAX   ;
        for(int i=0;i<temp;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            if(dis1[u]==LONG_LONG_MAX || dis2[v]==LONG_LONG_MAX){
                continue;
            }
            int cost=dis1[u]+(wt/2)+dis2[v];
            ans=min(ans,cost);
        }

        cout<<ans<<endl;

}