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
}edge1;

bool cmpEdge(const edge1& a, const edge1& b) {
    return a.wt < b.wt;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<node> nodes(n);
    for(int i=0;i<n;i++){
        cin>>nodes[i].x>>nodes[i].y>>nodes[i].z;
        nodes[i].index=i;
    }
    vector<edge1> edges;
    // Sort by x
    vector<pair<int, int>> sorted(n);
    for (int i = 0; i < n; ++i) {
        sorted[i] = {nodes[i].x, i};
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n - 1; ++i) {
        int u = sorted[i].second, v = sorted[i + 1].second;
        int cost = min({
            abs(nodes[u].x - nodes[v].x),
            abs(nodes[u].y - nodes[v].y),
            abs(nodes[u].z - nodes[v].z)
        });
        edges.push_back({u, v, cost});
    }

    for (int i = 0; i < n; ++i) {
        sorted[i] = {nodes[i].y, i};
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n - 1; ++i) {
        int u = sorted[i].second, v = sorted[i + 1].second;
        int cost = min({
            abs(nodes[u].x - nodes[v].x),
            abs(nodes[u].y - nodes[v].y),
            abs(nodes[u].z - nodes[v].z)
        });
        edges.push_back({u, v, cost});
    }

    for (int i = 0; i < n; ++i) {
        sorted[i] = {nodes[i].z, i};
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n - 1; ++i) {
        int u = sorted[i].second, v = sorted[i + 1].second;
        int cost = min({
            abs(nodes[u].x - nodes[v].x),
            abs(nodes[u].y - nodes[v].y),
            abs(nodes[u].z - nodes[v].z)
        });
        edges.push_back({u, v, cost});
    }


    disjointset ds(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        ds.unionbyrank(a,b);
    }

    sort(edges.begin(),edges.end(),cmpEdge);

    long long int total=0;
    for(auto &it:edges){
        if(ds.upar(it.u)!=ds.upar(it.v)){
            total+=it.wt;
            ds.unionbyrank(it.u,it.v);
        }
    }
    cout<<total<<endl;


}
