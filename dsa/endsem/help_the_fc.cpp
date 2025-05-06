#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<int,int>> val(n);
    vector<pair<int,int>> x;
    vector<pair<int,int>> y;
    for(int i=0;i<n;i++){
        cin>>val[i].first>>val[i].second;
    }
    sort(val.begin(),val.end(),[&](pair<int,int> a,pair<int,int> b){
        return (a.first-a.second)>(b.first-b.second);
    });
    int total=0;
    for(int i=0;i<val.size();i++){
        total+=val[i].first*(i) + val[i].second*(n-i-1);
    }
    cout<<total<<endl;


}