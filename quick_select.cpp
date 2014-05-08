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
    quickSort(A, lo, pivot-1);
    quickSort(A, pivot+1, hi);
    
}

// find kth smallest
int quickSelect(vector<int>& A, int k, int lo, int hi){
    int pivot = partition(A, lo, hi);
    
    if (pivot+1 == k) 
        return A[pivot];
    else if (pivot + 1 > k)
        return quickSelect(A, k, lo, pivot-1);
    else 
        return quickSelect(A, k, pivot+1, hi);
}


int main()
{    
    vector<int> testqs = {9,5,1,2,7,88,-4,15};
    quickSort(testqs, 0, testqs.size() -1);
    for (int i : testqs) cout << i << ", ";
    cout << endl;
    
    cout << quickSelect(testqs, 4, 0, testqs.size()-1);
    

   return 0;
}


