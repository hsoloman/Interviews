#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& A){
    for(int i : A){
        cout << i << ", ";
    }    
    cout << endl;
}


void print_partitions(int target, int max, vector<int> result){
    
    if (target == 0) print(result);
    
    for (int i = 1; i <= max && i<=target; ++i){ 
        vector<int> temp(result);
        temp.push_back(i);
        print_partitions(target-i, i, temp);
    }
}


int main()
{
   cout << "Printing all partitions of 4" << endl; 
   print_partitions(4,4, vector<int>());
   
   return 0;
}
