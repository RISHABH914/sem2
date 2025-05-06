#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> val(n);
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        vector<unordered_map<int,int>> graph(n);
        vector<vector<int>> another(n);
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            a--,b--;
            graph[a][val[b]]++;
            graph[b][val[a]]++;
            another[a].push_back(b);
            another[b].push_back(a);
        }
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            if(res[val[i]-1]){
                continue;
            }
                for(auto it:graph[i]){
                    if(it.second>=2){
                        res[it.first -1]=1;
                    }else if(it.second==1 && it.first==val[i]){
                        res[val[i]-1]=1;
                    }
                }
            
        }
        for(int i=0;i<n;i++){
            cout<<res[i];
        }
        cout<<endl;

    }

}