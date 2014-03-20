#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  	int numCenters(0);
	cin >> numCenters;

	map<int, set<int> > datacenters; 
	map<int, set<int> > dataLocations;
	set<int> data;

	for (int center = 1 ; center <= numCenters; center++){
		int numids(0);
        	cin >> numids;

		int temp(0);
		for (int j = 0 ; j < numids ; j++){
			cin >> temp;
			datacenters[center].insert(temp);
			dataLocations[temp].insert(center);
            		data.insert(temp);
		}
	}

	// for each data center, iterate through all data,
	// if not found, index dataLocations and pull first location
	// print dataid, data center, first location 

	for (int i = 1 ; i <= numCenters ; i++){
        
		for (set<int>::iterator it = data.begin() ; it != data.end(); ++it){
			// if datacenters[i] doesn't have it
			if (datacenters[i].find(*it) == datacenters[i].end()){
				int firstLocation = *(dataLocations[*it].begin());
				cout << *it << " " << firstLocation << " " << i << endl;
			}
		}
	}
    
    cout << "done" << endl;

}
