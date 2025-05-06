#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,pair<int,int>> pp;
int dijkstra(vector<vector<int>>& grid,int n){
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    vector<vector<int>> dist(2,vector<int>(n,LONG_LONG_MAX));
    dist[0][0]=0;
    pq.push({dist[0][0],{0,0}});
    vector<int> dx={0,0,1,1,1,-1,-1,-1};
    vector<int> dy={1,-1,0,1,-1,0,1,-1};
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        int x=node.second.first;
        int y=node.second.second;
        if (node.first > dist[x][y]) continue;
       
        for(int i=0;i<8;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx<0 || newy<0 || newx>=2 || newy>=n){
                continue;
            } 
            int add=0;
            if(grid[newx][newy]){
                add=1;
            }
            if(dist[newx][newy]>node.first+add){
                dist[newx][newy]=node.first+add;
                pq.push({dist[newx][newy],{newx,newy}});
            }
        }
    }
    return dist[1][n-1];
}
signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> grid(2,vector<int> (n));
        string a;
        cin>>a;
        for(int i=0;i<n;i++){
            grid[0][i]=a[i]-'0';
        }
        cin>>a;
        for(int i=0;i<n;i++){
            grid[1][i]=a[i]-'0';
        }
        grid[1][n-1]=0;
        grid[0][0]=0;
        cout<<dijkstra(grid,n)<<endl;
    }    

}