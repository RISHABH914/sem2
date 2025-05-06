#include<bits/stdc++.h>
using namespace std;
#define int long long
int dijkstra(vector<int>& dst,vector<vector<int>>& graph,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,1});

    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        if(temp.first>dst[temp.second]){
            continue;
        }

        int node=temp.second;
        for(auto it:graph[node]){
            if(dst[it]>dst[node]+1){
                dst[it]=dst[node]+1;
                pq.push({dst[it],it});
            }
        }
    }
    return dst[n-1];
}

void bfs(vector<int>& indegree,vector<vector<int>>& graph){
    queue<int> qp;
    int n=graph.size();
    vector<int> vis(n+1,0);
    qp.push(1);
    while(!qp.empty()){
        int node=qp.front();
        qp.pop();
        vis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
            indegree[it]++;
            qp.push(it);
            }
        }
    }
}
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1,0);
    queue<int> qp;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    vector<int> topo;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            qp.push(i);
        }
    }
    vector<int> temp(n+1,LONG_LONG_MAX);
   
    if( dijkstra(temp,graph,n+1)==LONG_LONG_MAX){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> vis(n+1,0);
    while(!qp.empty()){
        int node=qp.front();
        topo.push_back(node);
        vis[node]=1;
        qp.pop();
        for(auto it:graph[node]){
            if(!vis[it]){
            indegree[it]--;
            if(indegree[it]==0){
                qp.push(it);
            }
            }
        }
    }
    vector<int> dist(n+1,0);
    dist[n]=1;
    int i=n-1;
    while(topo[i]!=n){
        i--;
    }
    i--;
    for(;i>=0;i--){
        for(auto it:graph[topo[i]]){
            dist[topo[i]]=max(dist[topo[i]],dist[it]+1);
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    cout<<dist[1]<<endl;
}