#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> arrays(n);
    vector<pair<long long, int>> sumIndex(n); // (total sum, index)

    // Read input and calculate the sum of each array
    for (int i = 0; i < n; i++) {
        long long totalSum = 0;
        arrays[i].resize(m);
        
        for (int j = 0; j < m; j++) {
            cin >> arrays[i][j];
            totalSum += arrays[i][j];
        }

        sumIndex[i] = {totalSum, i};  // Store (sum, index)
    }

    // Sort arrays in descending order of their total sum
    sort(sumIndex.rbegin(), sumIndex.rend());

    // Compute the maximum score
    long long finalScore = 0, cumulativeSum = 0;
    
    for (auto &p : sumIndex) { // Correct unpacking of pair
        long long sum = p.first, index = p.second;
        for (long long num : arrays[index]) {
            cumulativeSum += num;  // Maintain running prefix sum
            finalScore += cumulativeSum;
        }
    }

    cout << finalScore << endl;
    }
    return 0;
}
