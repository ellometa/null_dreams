#include <bits/stdc++.h>
using namespace std;
#define ll long long 


ll t = 1;

void say(){
    
  
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {4, 5, 6, 7, 8};
    int c[5] = {7, 8, 9, 10, 11};
  
    int sum1 = 0;
  
    // O(n^3)
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                sum1 += a[i] * b[j] * c[k];
            }
        }
    }

  
}



int32_t main() {
  
  cin >> t;
  
  while (t--){
    say();
  }
}