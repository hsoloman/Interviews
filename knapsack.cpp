#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Basic DP knapsack solution. Each item can only be picked once.

int best(const vector<pair<int, int>>& cakes, int n, int weight) {
    
    if (n == 0) { return 0; }
    if (weight == 0) { return 0; }
    
    if (cakes[n-1].first > weight) {
        return best(cakes, n-1, weight);    
    }
    
    return max( best(cakes, n-1, weight - cakes[n-1].first) + cakes[n-1].second, 
                best(cakes, n-1, weight));
}

int bestDP(const vector<pair<int, int>>& cakes, int n, int weight) {
    int table[n+1][weight+1];
    
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= weight ; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
                continue;
            }
            
            if (cakes[i-1].first > j) {
                table[i][j] = table[i-1][j];  
            } else {
                table[i][j] = max(table[i-1][j], table[i-1][j - cakes[i-1].first] + cakes[i-1].second);
            }
        }    
    }
    
    return table[n][weight];
}

int main()
{
    vector<pair<int, int>> cakes = {{2,3}, {4,2}, {6,1}, {7, 20}, {4, 0}, {1, 2}, {8, 10}};
    cout << "best: " << best(cakes, cakes.size(), 6) << endl;
    cout << "bestDP: " << bestDP(cakes, cakes.size(), 6) << endl;

}
