#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n);
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
    }
    unordered_set<int> another;
    for(int i=1;i<n;i++){
        another.insert(i);
    }
    unordered_set<int> main;
    main.insert(0);
    while(!another.empty()){
        auto temp=another.begin();
        int node=*temp;
        for(auto it:graph[node]){
            
        }
    }


}