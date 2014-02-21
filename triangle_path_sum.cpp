// NOT DONE YET

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

namespace {
    typedef vector<vector<int> > triangle_t;    
    
    void growTriangle(triangle_t& tri, const string& ln){
        istringstream ss(ln);
        vector<int> row;
        int n;
        while(ss >> n){row.push_back(n);}
        tri.push_back(row);
    }
    
    void printTriangle(const triangle_t& tri){
        for (const vector<int> &row : tri){
            for (const int n : row){
                cout << n << ' ';
            }
            cout << endl;
        }
    }
    
    bool validateTriangle(const triangle_t& tri){
        for (int i = 0; i < tri.size(); i++){
            if (tri[i].size() != i+1) return false;
        }
        return true;
    }
    
    int maxSum(const triangle_t& tri){
        
        
        
    }
}

int main(int argc, char** argv)
{           
    triangle_t triangle;
    
    ifstream file;
    file.open(argv[1]);
    
    string row;
    
    while (!file.eof()) {
        getline(file, row);
        if (row.length() == 0) continue; 
        else {
            growTriangle(triangle, row);  
        }
    }
    
    if (!validateTriangle(triangle)){return 1;}
    
    
    

    return 0;
}
