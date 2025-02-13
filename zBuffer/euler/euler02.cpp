#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    // 1 2 3 5 8 13
    
    int a = 1, b = 2, sum = 0;
    
    // cout << a << " ";
    
    while (b < 4000000){
        // cout << b << " ";
        
        if (b%2 == 0){
            sum += b;
        }
        
        b+=a;
        a = b - a;
    }
    
    cout newline;
    cout << sum ;
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