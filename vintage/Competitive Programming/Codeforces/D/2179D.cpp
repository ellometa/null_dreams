#include<bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*
    
*/
 
// Small Observatins
/*
    whats the structure of sacred permutatoin...

    should u start with all 1s ?

        if not, swap all 1s with a0.
            then 

    all 1s must be first.

    now u have n - 1 1s..


    1 1 1 1
    1 1 1 1
    1 1 0 0
    1 0 0 1

    1 1 1 1
    1 1 1 1
    1 1 0 0
    1 0 0 1

    1 0

    1 1 0 0
    1 0 0 1


    1 1 1 1 0 0 0 0   
    1 1 0 0 0 0 1 1 
    1 0 0 1 0 1 0 1 


    3 1 0 2

    1 1 1 1 1 1 1 1
    1 1 1 1 0 0 0 0
    1 1 0 0 0 0 1 1
    1 0 0 1 0 1 0 1
*/
 
 
 
/*

*/
 
 
// Claims on algo 
/*  
    
 
*/


void solve(){
    int n; cin >> n;
    cout << (1 << n) - 1 << ' ';

    for (int k = n - 1; k >= 0; k--){
        int b = k + 1;
        int rem = (n - b);
        int suff = (1 << b) - 1;
        suff ^= (1 << (b - 1));
        for (int i = 0; i < (1 << rem); i++) cout << ((i << b) ^ suff) << ' ';
    }
    cout << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}
 
// Golden Rules
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.
 
*/
