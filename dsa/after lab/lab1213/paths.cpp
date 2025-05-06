#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    queue<pair<int,int>> qp;
    qp.push({1,0});
    vector<int> vis(n+1,0);
    vis[1]=1;
    int cnt=0;
    int min=INT_MAX;
    while(!qp.empty()){
        auto temp=qp.front();
        int node=qp.front().first;
        vis[node]=1;
        qp.pop();
        if(node==n){
            if(temp.second<min){
                min=temp.second;
                cnt=1;
            }else if(temp.second==min){
                cnt++;
            }
            continue;
        }
        for(auto it:graph[node]){
            if(!vis[it]){
                qp.push({it,temp.second+1});
            }
        }
    }
    cout<<cnt<<endl;
}