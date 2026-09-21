#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int l, b, p; cin >> l >> b >> p;
    int minr = +INF, r= 0;
    
    for (int i = 1; i <= l; i++){
        for (int j = 1; j <= b; j++){
            r = 2*i+2*j;
            minr = min((abs(r - p)), minr);
        }
    }
    
    cout << minr  newline;
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