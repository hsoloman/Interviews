#include <iostream>
#include <string>

using namespace std; 

int isSubstringBF(const string & A, const string & b)
{
    const int stop = A.size() - b.size();
    for (int i = 0 ; i < stop ; ++i){
        bool match(true);
        for (int j = 0; j < b.size() ; ++j){
            if (A[i+j] != b[j]) {
                match = false;
                break;
            }
        }
        if (match) return 1;
    }
        
    return 0;
}

int isSubstring(const string & A, const string & b)
{
    return isSubstringBF(A, b);
}

int main(){

    string A, b;
    for (int i = 0 ; i < 24 ; ++i){
        cin >> A >> b;
        
        cout << isSubstring(A, b) << endl;
        
    }


	return 0;
}
