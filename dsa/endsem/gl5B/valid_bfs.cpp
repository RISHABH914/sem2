#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> arr(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    if (arr[0] != 1)
    {
        cout << "No" << endl;
        return 0;
    }
    queue<int> qp;
    qp.push(1);
    vector<int> vis(n + 1, 0);
    int index = 1;
    while (!qp.empty())
    {

        vector<int> temp;
        int node = qp.front();
        qp.pop();
        vis[node] = 1;
        int newmax = 0;
        for (auto it : graph[node])
        {
            if (vis[it])
            {
                continue;
            }
            temp.push_back(it);
        }

        sort(temp.begin(), temp.end(), [&](int a, int b)
             { return mp[a] < mp[b]; });

        for (auto it : temp)
        {
            if (mp[it] != index)
            {
                cout << "No" << endl;
                return 0;
            }
            else
            {
                index++;
                qp.push(it);
            }
        }
    }
    cout << "Yes" << endl;
}