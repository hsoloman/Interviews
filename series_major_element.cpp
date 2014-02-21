#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

string getMajorElement(const string& tokens){
    map<string, int> mp;
            
    istringstream ss(tokens);
    string token;
    int numTokens(0);

    while(getline(ss, token, ',')){
        numTokens++;
        if(mp.count(token)){
            mp.find(token)->second++;
        } else {
            mp.insert( std::pair<string, int>(token, 1));
        }
    }
        
    for(pair<string, int> p : mp){
        if (p.second >= numTokens/2) {
            return p.first;  
        }
    }
    
    return "None";
}

int main(int argc, char** argv)
{
    ifstream file;
    file.open(argv[1]);
    
    string lineBuffer;
    
    while (!file.eof()) {
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0)
            continue; 
        else {
            cout << getMajorElement(lineBuffer) << endl;
        }
    }
    return 0;
}
