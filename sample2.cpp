#include <bits/stdc++.h>
using namespace std;
#define ll long long 



int do_something_with_integers(int a, int b = 0){
    
    return a+b;
    
    
}


void say(){
    
    int n; cin >> n;
    
    int summation = 0; 
    
    for (int i = 1; i <= n; i++){
        summation = do_something_with_integers(summation, i);
    }
    cout << summation << '\n';
  
}



int32_t main() {
    int t = 1;
    cin >> t;
    
    while (t--){
        say();
    }
}