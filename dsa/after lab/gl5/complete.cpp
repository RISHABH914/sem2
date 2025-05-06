#include <iostream>
#include<cmath>
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

signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int n,m,l,s,t;
    cin>>n>>m>>l>>s>>t;
    vector<vector<pair<int,int>>> graph(n);
    vector<vector<pair<int,int>>> temp(n);

    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        if(!wt){
            wt++;
       graph[a].push_back({b,wt});
       graph[b].push_back({a,wt});
       continue;
        }
       graph[a].push_back({b,wt});
       graph[b].push_back({a,wt});

       
       temp[a].push_back({b,wt});
       temp[b].push_back({a,wt});
    }
    vector<int> dist1(n,LONG_LONG_MAX);
    dist1[s]=0;
    vector<int> dist2(n,LONG_LONG_MAX);
    dist2[s]=0;

    dijkstra(dist1,graph,n,s);
    dijkstra(dist2,temp,n,s);
    if(dist2[t]<l){
        cout<<"NO"<<endl;
        return 0;
    }

    if(dist2[t]==l || (dist1[t]<=l)){
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;


}