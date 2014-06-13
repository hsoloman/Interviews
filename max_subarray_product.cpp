#include <iostream>
#include <vector>

using namespace std;

int maxSubarrayProduct(const vector<int>& A)
{
    int maxEndingHere(1);
    int minEndingHere(1);
    int maxSoFar(1);
    
    for (int i : A){
        if (i == 0){
            // TODO 
            // setting to 1 to continue with iterations
            // need to handle special case where all possible
            // products return 0
            
            maxEndingHere = 1;
            minEndingHere = 1;
        } else {
            maxEndingHere = std::max(std::max(maxEndingHere*i, 1), 
                                minEndingHere*i);
            minEndingHere = std::min(std::min(minEndingHere*i, 1), 
                                maxEndingHere*i);
        }
        
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}



int main()
{ 
   vector<int> test = {1,2,3,4,0,-10,-20};
   
   cout << "maxSubarrayProduct = " << maxSubarrayProduct(test);
   return 0;
}
