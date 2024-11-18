#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n; cin >> n;
    if(n<1){cout << 0 newline; return;}
    vector<int> vecarr(n);
    for (auto&x:vecarr){cin >> x;}
    sort(all(vecarr));

    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        if (vecarr[i] == vecarr[i + 1]) {
            counter++;
            i++; 
        }
    }

    cout << counter newline;
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
/*
1 1 2 2 3 3
*/