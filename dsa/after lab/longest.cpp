#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    vector<int> indegree(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    queue<int> qp;
    vector<int> topo;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            qp.push(i);
        }
    }
    while(!qp.empty()){
        int node=qp.front();
        topo.push_back(node);
        qp.pop();
        for(auto it:graph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                qp.push(it);
            }
        }

    }

    vector<int> ways(n,0);
   for(int i=n-1;i>=0;i--){
    int u=topo[i];
    for(auto it:graph[u]){
        ways[u]=max(ways[u],1+ways[it]);
    }
   }

   for(int i=0;i<n;i++){
    cout<<ways[i]<<" ";
   }

}