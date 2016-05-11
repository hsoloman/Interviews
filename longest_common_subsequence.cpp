#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void printLS(const vector<vector<int>>& LS) {
    for (const auto& row : LS) {
        for (const auto& item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
}

void Backtrack(const vector<vector<int>>& LS, const vector<int>& A, const vector<int>& B,
               int i, int j, vector<int>& result) {
    if (i == 0 || j == 0) {return;}
    
    if (A[i-1] == B[j-1]) {
        result.push_back(A[i-1]);
        Backtrack(LS, A, B, i-1, j-1, result);
        
    } else if (LS[i][j-1] > LS[i-1][j]) {
        Backtrack(LS, A, B, i, j-1, result);
        
    } else {
        Backtrack(LS, A, B, i-1, j, result);
    }
}

void PrintLongestSubsequence(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    int m = B.size();
    
    // Initialize DP table.
    vector<vector<int>> LS(n+1);
    for (auto& v : LS) {v = vector<int>(m+1);}

    // Fill DP table.
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            // if A[i-1] == B[j-i], set to LS[i-1][j-1] + 1
            // otherwise, set to max(LS[i][j-1], LS[i-1][j])
            if (A[i-1] == B[j-1]) {
                LS[i][j] = LS[i-1][j-1] + 1;
            } else {
                LS[i][j] = max(LS[i][j-1], LS[i-1][j]);
            }
        }
    }
    
//    printLS(LS);
//    int longest = LS[n][m];
//    cout << "LS = " << longest << endl;
    
    vector<int> result;
    Backtrack(LS, A, B, n, m, result);
    reverse(result.begin(), result.end());
    
    for (int i : result) {cout << i << " ";}
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0 ; i < n ; i++) {
        cin >> A[i];
    }
    for (int i = 0 ; i < m ; i++) {
        cin >> B[i];
    }
    
    PrintLongestSubsequence(A, B);
    return 0;
}
