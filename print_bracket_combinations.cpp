#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Helper(const string& s, int open, int close, int n) {
    if (open == n && close == n) {
        cout << s << endl;
    }
    if (open < n) {
        Helper(s + "{", open + 1, close, n);
    }
    if (close < open) {
        Helper(s + "}", open, close + 1, n);    
    }
}

void PrintAllBrackets(int n) {
    Helper("", 0, 0, n);
}

int main() {
    PrintAllBrackets(1);
    cout << endl;
    PrintAllBrackets(2);
    cout << endl;
    PrintAllBrackets(3);
    
    return 0;
}
