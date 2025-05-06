#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int cmp(const pair<int,long long>& a,const pair<int,long long>& b){
    return a.second<b.second;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, long long>>> graph(n + 1); // Use long long for weights
    while (m--) {
        int a, b;
        long long wt; // Use long long for weight input
        cin >> a >> b >> wt;
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n + 1, LLONG_MAX); 
    vector<bool> visited(n + 1, false); 

    dist[1] = 0; 
    pq.push({0, 1}); 

    while (!pq.empty()) {
        auto temp = pq.top();
        long long wt = temp.first;
        int node = temp.second;
        pq.pop();

        if (visited[node]) continue; 
        visited[node] = true;

        for (auto it : graph[node]) {
            int next_node = it.first;
            long long edge_wt = it.second;
            if (dist[next_node] > dist[node] + edge_wt) {
                dist[next_node] = dist[node] + edge_wt;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    int count = 0;
    vector<pair<int,long long>> queries(k);
    for(int i=0;i<k;i++){
        cin>>queries[i].first>>queries[i].second;
    }
    sort(queries.begin(),queries.end(),cmp);
    for(int i=0;i<k;i++) {
        int a=queries[i].first;
        long long wt=queries[i].second; 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        if (dist[a] <= wt) {
            count++;
        }else{
            dist[a]=wt;
            pq.push({dist[a],a});
        }

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            int node=temp.second;
            for(auto it:graph[node]){
                if(dist[it.first]>dist[node]+it.second){
                    dist[it.first]=dist[node]+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<endl;
    // }
    cout << count << endl;
    return 0;
}