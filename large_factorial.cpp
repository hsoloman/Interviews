#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PrintVector(const vector<int>& vector) {
    for (int i = 0 ; i < vector.size() ; i++) {
        cout << vector[i];
    }
}

vector<int> Add(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    auto lit = left.rbegin();
    auto rit = right.rbegin();
    
    int carry = 0;
    while (lit != left.rend() && rit != right.rend()) {
        int sum = *lit + *rit + carry;
        carry = sum/10;
        sum = sum%10;
        result.insert(result.begin(), sum);
        lit++;
        rit++;
    }
    
    while (lit != left.rend()) {
        int sum = *lit + carry;
        carry = sum/10;
        sum = sum%10;
        result.insert(result.begin(), sum);
        lit++;    
    }
    while (rit != right.rend()) {
        int sum = *rit + carry;
        carry = sum/10;
        sum = sum%10;
        result.insert(result.begin(), sum);
        rit++;    
    }    
    if (carry> 0) {
        result.insert(result.begin(), carry);
    }
    
    return result;
}

// carry is not limited to 1 digit
void Multiply(vector<int>& number, int n) {
//    cout << "multiply: ";
//    PrintVector(number);
//    cout << " by : " << n << endl;
    
    vector<int> total = {0};
    
    int power = 0;
    while (n > 0) {
        int multiplier = n%10;
        int carry(0);
        vector<int> temp = number;
        for (int i = temp.size() - 1 ; i >= 0 ; i--) {
            int result = temp[i] * multiplier + carry;
            carry = result/10;
            temp[i] = result%10;
        }
        if (carry > 0) {
            temp.emplace(temp.begin(), carry);
        }    
        for (int i = 0 ; i < power ; i++) {
            temp.emplace_back(0);
        }
        
        total = Add(total, temp);
        power++;
        n /= 10;
    }
    
    number = total;
}

void PrintLargeFactorial(int n) {
    vector<int> number = {1};
    for (int i = 2 ; i <= n ; i++) {
        Multiply(number, i);
    }
    PrintVector(number);
}

int main(){
    int n;
    cin >> n;
    
    PrintLargeFactorial(n);
    return 0;
}
