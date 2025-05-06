#include<bits/stdc++.h>
#define int long long
using namespace std;

void dijkstra(vector<int>& dst,vector<vector<pair<int,int>>>& graph,int n,int index){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,index});

    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();

        int node=temp.second;
        int weight=temp.first;
        if(weight>dst[node]){
            continue;
        }
        for(auto it:graph[node]){
            if(dst[it.first]>dst[node]+it.second){
                dst[it.first]=dst[node]+it.second;
                pq.push({dst[it.first],it.first});
            }
        }
    }
}

signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n);
    vector<vector<pair<int,int>>> graph1(n);
    vector<vector<int>> edges(m,vector<int> (3));
    for(int i=0;i<m;i++){
        int a,b;
        int wt;
        cin>>a>>b>>wt;
        a--,b--;
        graph[a].push_back({b,wt});
        graph1[b].push_back({a,wt});
        edges[i][0]=a,edges[i][1]=b,edges[i][2]=wt;

    }

    vector<int> dist(n,LONG_LONG_MAX);
    dist[0]=0;
    dijkstra(dist,graph,n,0);

    vector<int> dist1(n,LONG_LONG_MAX);
    dist1[n-1]=0;
    dijkstra(dist1,graph1,n,n-1);
    int maxans=LONG_LONG_MAX;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        if(dist[u]==LONG_LONG_MAX || dist1[v]==LONG_LONG_MAX){
            continue;
        }
            maxans=min(maxans,dist[u]+(wt/2)+dist1[v]);
        
    }
    cout<<maxans<<endl;
}
