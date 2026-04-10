#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    
    
    int a, b, n; cin >> a >> b >> n;
    int res = a;
    for (int i = 0; i < n ; i++){
        res = res*10 + 1;
    }
    cout << res newline;
    
    // double res = a* pow (10, n);
    cout << b*(ceil(res/b)) newline;  
    
    // if ((int)ceil(res/b) % b == 0){
        
    // }
    // else{
    //     cout << -1 newline;
    // }
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