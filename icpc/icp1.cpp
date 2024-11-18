#include <bits/stdc++.h>
#define AKY AayushKYadav ^_^
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long 
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> d1, d2; 
    set<int> keys; 
    int count = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int product = x * y;
        d1[product]++;
        keys.insert(product); 
    }


    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int product = x * y;
        d2[product]++; 
        keys.insert(product); 
    }

    for (auto x : keys) {
        count += min(d1[x], d2[x]);
    }

    cout << count << endl; 
}

int32_t main() {
    IOS
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}
