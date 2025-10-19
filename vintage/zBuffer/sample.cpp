#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 6, 4, 6};

    auto it = find(vec.begin(), vec.end(), 6);  
    // Search for 6

    if (it != vec.end()) {
        
        int index = it - vec.begin();
        
        cout << "Element found " << *it <<" at index: " << index << endl;
        
    } 
    else {
        cout << "Element not found" << endl;
    }

    return 0;
}
