#include <iostream>
#include <vector>
using namespace std;

int partition (vector<int> & A, int lo, int hi){
    int i(lo), j(hi + 1);
    int pivot = A[lo];

    while (1){
        while ( A[++i] < pivot );
        while ( A[--j] > pivot );
        if (i >= j) break;
        swap(A[i], A[j]);
    }
    swap( A[lo], A[j] );
    return j;
}

void quickSort(vector<int>& A, int lo, int hi){
    if (lo >= hi) return;
    
    int pivot = partition(A, lo, hi);
    quickSort(A, lo, pivot -1);
    quickSort(A, pivot+1, hi);
    
}

int main()
{
    vector<int> test = {9,5,1,2,7,88,-4,2,15};
    int pivot = partition(test, 0, test.size()-1);    
    for (int i : test) cout << i << ", ";
    
    cout << endl;
    
    vector<int> testqs = {9,5,1,2,7,88,-4,2,15};
    quickSort(testqs, 0, testqs.size() -1);
    for (int i : testqs) cout << i << ", ";

   return 0;
}
