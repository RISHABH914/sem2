#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    vector<int> indegree(n,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[b].push_back(a);
        indegree[a]++;
    }

    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            pq.push(i);
        }
    }
    vector<int> res;
    while(!pq.empty()){
        int node=pq.top();
        res.push_back(node);
        pq.pop();
        for(auto it:graph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                pq.push(it);
            }
        }

    }
    vector<int> final(n);
    int temp=0;
    for(int i=0;i<n;i++){
        final[res[i]]=n-(temp+1);
        temp++;
    }

    for(int i=0;i<n;i++){
        cout<<final[i]<<" ";
    }

}