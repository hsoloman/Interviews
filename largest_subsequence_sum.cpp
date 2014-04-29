#include <iostream>
#include <vector>

using namespace std;

int largestSubsequenceSum(const vector<int> & sequence)
{
    if (sequence.size() == 0) return 0;
    int maxEndingHere(sequence[0]), maxSoFar(sequence[0]); // base case
    
    // every case
    for (size_t i = 1 ; i < sequence.size(); ++i){
        if (sequence[i] > maxEndingHere + sequence[i]){
            maxEndingHere = sequence[i];
        } else {
            maxEndingHere += sequence[i];
        }

        if (maxSoFar < maxEndingHere){
            maxSoFar = maxEndingHere;
        }
    }
    
    return maxSoFar;
}

int sum(const vector<int> & sequence, int start, int end){
    int sum(0);
    for (size_t i = start ; i <= end ; ++i){
        sum += sequence[i];
    }
    return sum;
}

int largestSubsequenceDumb(const vector<int> & sequence)
{
    int largest(0);
    
    for (size_t start = 0; start < sequence.size() ; ++start){
        for (size_t end = start ; end < sequence.size() ; ++end){
            int temp = sum(sequence, start, end);
            if (temp > largest)
                largest = temp; 
        }
    }
    return largest;
} 



int main()
{
    vector<int> testSequence = {1, 2, 3, -1, 4, -10, 1, 20};
    
    cout << "largestSubsequenceSum() = " << largestSubsequenceSum(testSequence) << endl;
    cout << "brute force solution = " << largestSubsequenceDumb(testSequence) << endl;
    
    return 0;
}
