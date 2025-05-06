#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

class disjointset{
    vector<int> rank,parent;

    public:
        disjointset(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int upar(int node){
            if(node==parent[node]){
                return node;
            }
            parent[node]=upar(parent[node]);
            return parent[node];
        }

        void unionbyrank(int u,int v){
            int ulu=upar(u);
            int ulv=upar(v);
            if(ulu==ulv){
                return;
            }
            if(rank[ulu]<rank[ulv]){
                parent[ulu]=ulv;
            }else if(rank[ulv]<rank[ulu]){
                parent[ulv]=ulu;
            }else{
                parent[ulv]=ulu;
                rank[ulu]++;
            }
        }
};

typedef struct node{
    int x,y,z,index;
}node;

typedef struct edge1{
    int u,v,wt;
    bool operator<(const edge1& other) const{
        return wt<other.wt;
    }
}edge1;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<node> nodes(n);
    for(int i=0;i<n;i++){
        cin>>nodes[i].x>>nodes[i].y>>nodes[i].z;
        nodes[i].index=i;
    }

    disjointset ds(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        ds.unionbyrank(a,b);
    }

    vector<int> vis(n,0);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    long long int total=0;
    int edges=0;

    vis[0]=1;
    for(int j=1;j<n;j++){
        if(!vis[j]){
            int cost=min({abs(nodes[j].x - nodes[0].x),abs(nodes[j].y - nodes[0].y),abs(nodes[j].z - nodes[0].z)});
            pq.push({cost,{0,j}});
        }
    }

    while(!pq.empty()){
        auto temp=pq.top();
        int u=temp.second.first;
        int v=temp.second.second;
        int wt=temp.first;
        pq.pop();
        if(vis[v]){
            continue;
        }

        if(ds.upar(u)!=ds.upar(v)){
            ds.unionbyrank(u,v);
            total+=wt;
            edges++;
        }

        vis[v]=1;

        for(int j=0;j<n;j++){
            if(!vis[j]){
                int cost=min({abs(nodes[v].x - nodes[j].x),abs(nodes[v].y - nodes[j].y),abs(nodes[v].z - nodes[j].z)});
                pq.push({cost,{v,j}});
            }
        }
    }

    cout<<total<<endl;


}