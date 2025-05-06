#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef pair<int,pair<short int,short int>> pii;
short int solve(vector<vector<short int>>& graph,short int n,short int m){
    // deque<pii> dq;
    queue<pii> q1;
    queue<pii> q2;
    int perm[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    // dq.push_front({0,{0,0}});
    q1.push({0,{0,0}});
    vector<vector<int>> res(n,vector<int> (m,INT_MAX));
    res[0][0]=0;
    while(!q1.empty() || !q2.empty()){
        pii temp;
        if(!q1.empty()){
            temp=q1.front();
            q1.pop();
        }else{
            temp=q2.front();
            q2.pop();
        }
        int count=temp.first;
        int x=temp.second.first;
        int y=temp.second.second;
        if(x==n-1 && y==m-1){
            return count;
        }
        for(int i=0;i<4;i++){
            int newx=x+perm[i][0];
            int newy=y+perm[i][1];

            if(newx<0 || newx>=n || newy<0 || newy>=m){
                continue;
            }
                if(graph[x][y]==graph[newx][newy]){
                    if(res[newx][newy]>count){
                        res[newx][newy]=count;
                    q1.push({count,{newx,newy}});
                    }
                }else{
                    if(res[newx][newy]>count+1){
                        res[newx][newy]=count+1;
                    q2.push({count+1,{newx,newy}});
                    }
                }

        }
    }

        return res[n-1][m-1];
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    short int t;
    cin>>t;
    while(t--){
        short int n,m;
        cin>>n>>m;
        vector<vector<short int>> height(n,vector<short int> (m));
        for(short int i=0;i<n;i++){
            for(short int j=0;j<m;j++){
                cin>>height[i][j];
            }
        }
        cout<<solve(height,n,m)<<endl;
        
    }
}