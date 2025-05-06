#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main()
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

    queue<int> qp;
    vector<int> dist(n+1,INT_MAX);
    vector<int> ways(n+1,0);

    dist[1]=0;
    ways[1]=1;
    qp.push(1);
    while(!qp.empty()){
        int node=qp.front();
        qp.pop();
        for(auto it:graph[node]){
            if(dist[it]>dist[node]+1){
                dist[it]=dist[node]+1;
                ways[it]=ways[node];
                qp.push(it);
            }else if(dist[it]==dist[node]+1){
                ways[it]=(ways[it]+ways[node])%1000000007;
            }
        }
    }
    cout<<ways[n]<<endl;


}