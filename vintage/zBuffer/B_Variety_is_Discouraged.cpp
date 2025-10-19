#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    // 2 1 3 2
    // 1 2 3 3
    //encountering unique elements (use a freq array)
    // 1 1 1 1 1
    // 1 1 1 1 1
    
    //  8
    
    //  9   13  13  13  15  16  17  18
    
    //  1   2   2   2   3   4   5   6
    
    int n; cin >> n;
    vector<int> vecarr(n), freq(n, 0), ans(n+1, 0);
    for(auto &x:vecarr){
        cin>> x;
    }
    
    for(int i = 0; i < n; i++){
        
    }
        
    // 1 1 0 0 0 1 1
    
    
    
    

}

int32_t main() {
    IOS;

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}