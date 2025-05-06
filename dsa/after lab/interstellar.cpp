#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class disjointset {
    vector<int> parent;
    vector<long long> size;

public:
    disjointset(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int upar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = upar(parent[node]);
    }

    long long usize(int u) {
        return size[upar(u)];
    }

    void unionset(int u, int v) {
        int ulpu = upar(u);
        int ulpv = upar(v);
        if (ulpu == ulpv) {
            return;
        }
        if (size[ulpu] < size[ulpv]) {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        } else {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> edges(n); 
        for (int i = 1; i <= n - 1; i++) {
            cin >> edges[i].first >> edges[i].second;
        }

        disjointset graph(n);
        int q;
        cin >> q;
        vector<pair<char, int>> queries(q);
        unordered_map<int, int> mp;
        for (int i = 0; i < q; i++) {
            char op;
            cin >> op;
            queries[i].first = op;
            if (op == 'Q') {
                queries[i].second = -1;
            } else {
                int temp;
                cin >> temp; 
                mp[temp] = 1;
                queries[i].second = temp;
            }
        }

        long long count = (1LL * n * (n - 1)) / 2;
        for (int i = 1; i <= n - 1; i++) {
            if (mp.find(i) == mp.end()) {
                int u = edges[i].first;
                int v = edges[i].second;
                if (graph.upar(u) != graph.upar(v)) {
                    count -= graph.usize(u) * graph.usize(v);
                    graph.unionset(u, v);
                }
            }
        }

        stack<long long> sp;
        for (int i = q - 1; i >= 0; i--) {
            if (queries[i].first == 'Q') {
                sp.push(count);
            } else {
                int idx = queries[i].second;
                int u = edges[idx].first;
                int v = edges[idx].second;
                if (graph.upar(u) != graph.upar(v)) {
                    count -= graph.usize(u) * graph.usize(v);
                    graph.unionset(u, v);
                }
            }
        }

        while (!sp.empty()) {
            cout << sp.top() << endl;
            sp.pop();
        }
    }
    return 0;
}