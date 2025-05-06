#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

void nofonode(vector<vector<int>>& graph,int index,vector<int>& vis,int* total){
    vis[index]=1;
    (*total)++;
    for(auto it:graph[index]){
        if(!vis[it]){
            nofonode(graph,it,vis,total);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> graph(n+1);
        vector<pair<int,int>> edges(n-1);
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            edges[i].first=a;
            edges[i].second=b;
        }
        int q;
        cin>>q;
        int total=0;
        while(q--){
            char op;
            cin>>op;
            if(op=='Q'){
                cout<<total<<endl;
            }else{
                int edge;
                cin>>edge;
                int first=edges[edge-1].first;
                int second=edges[edge-1].second;
                auto temp=find(graph[first].begin(),graph[first].end(),second);
                graph[first].erase(temp);
                auto temp1=find(graph[second].begin(),graph[second].end(),first);
                graph[second].erase(temp1);
                vector<int> vis(n+1,0);
                int toal=0;
                int total1=0;
                nofonode(graph,first,vis,&toal);
                nofonode(graph,second,vis,&total1);
                total+=toal*total1;
            }
        }
    }

}