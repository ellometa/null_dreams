#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> t(n);
    for (int &x : t) cin >> x;

    vector<int> nxt(n, 1);
    int ans = 0;

    for (int day = 1; day <= d; ++day) {
        vector<pair<int, int>> bloom;
        for (int i = 0; i < n; ++i) {
            if (nxt[i] <= day) bloom.push_back({t[i], i});
        }

        int can = bloom.size() - k;
        if (can <= 0) continue;

        sort(all(bloom));

        for (int i = 0; i < can; ++i) {
            int idx = bloom[i].second;
            nxt[idx] = day + t[idx];
            ans++;
        }
    }

    cout << ans newline;
}

signed main(){
    IOS;

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
