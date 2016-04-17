#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void shuffle(vector<int>& deck) {
    const int size = deck.size();
	for (int i = size - 1; i > 0; i--) {
	    int j = rand() % (i + 1);
	    std::swap(deck[i], deck[j]);
	}
}

void print(const vector<int>& deck) {
	for (int i = 0 ; i < deck.size() ; i++){
		cout << deck[i] << endl;
	}
}


int main() {
	vector<int> deck = {1, 2, 3};
	srand (time(NULL));
	shuffle(deck);
	print(deck);
	return 0;
}
