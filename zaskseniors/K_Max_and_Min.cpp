#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int maxn = -INF, minn=INF;
    int a,b,c;
    for (int i = 0; i<3; i++){
        cin >> a;
        maxn = max(maxn, a);
        minn = min(minn, a);
    }
    cout <<  minn << " " << maxn newline;

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