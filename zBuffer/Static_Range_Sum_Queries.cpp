#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    
    int n,q; cin >> n >> q;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x; 
        v[i] = x;
    }
    
    vector<int> s(n+1, 0);
    
    
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + v[i-1];
    }//pre-processing
    
    // cout newline;
    // for (auto &x:s){cout << x newline;}
    
    for(int j = 0; j<q; j++){
        int l, r; cin >> l >> r;
        cout << s[r] - s[l-1] newline;
    }
}

int32_t main() {
    IOS;

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}