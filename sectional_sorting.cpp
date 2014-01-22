#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

namespace {
    typedef vector<vector<string> > list_t;
    typedef vector<string> sublist_t;

	enum input_t {INTEGER, WORD, NONE};


	bool is_word(const string& s){
		for (int i = 0 ; i < s.length() ; i++){
			if (!isalpha(s[i])) return false;
		}
		return true;
	}

	input_t input_type(const string& s){
		if (is_word(s)) return WORD;
        return INTEGER;
	}
    
    bool int_comp(string i, string j){
		return (atoi(i.c_str()) < atoi(j.c_str()));
	}

	void sort_sublist(sublist_t& sublist){
	        
        if (is_word(sublist.front())){
			std::sort(sublist.begin(), sublist.end());
		} else {
			std::sort(sublist.begin(), sublist.end(), int_comp);
		} 
    }

	void sort_list(list_t& list){
		int numSublists = list.size();
		for (int i = 0; i < numSublists; i++){
			sort_sublist(list[i]);
		}
	}

	void print_list(list_t& list){
		for (int i = 0; i < list.size() ; i++){
			for (int j = 0 ; j < list[i].size() ; j++){
				cout << list[i][j] << " ";
			}
		}
	}
}

int main() {

	list_t list;
	input_t currentType(NONE);
    
    ifstream infile;
    infile.open("input.txt");

	string temp;
	while(infile >> temp){
        
		// if type is not the same, add another sublist
		if (input_type(temp) != currentType){
			list.push_back(sublist_t());
            currentType = input_type(temp);
		}
		// add temp to last sublist
		list.back().push_back(temp);
        
	}

    sort_list(list);
	print_list(list);

	return 0;
}
