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


using namespace std;

int main()
{
    vector<int> test = {5,1,2,7,88,-4,2,15};
    
    int pivot = partition(test, 0, test.size()-1);
    
    for (int i : test) cout << i << ", ";

   return 0;
}
