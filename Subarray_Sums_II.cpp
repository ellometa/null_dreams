#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int n, q; 
    cin >> n >> q;

    vector<int> vecarr(n);
    for(auto &x:vecarr){cin>> x;}
    
    
    int prefix_sum = 0, ans = 0;
    map<int, int> mp;
    mp[0] = 1; // 

    for (int x : vecarr) {
        prefix_sum += x; 
        int complement = prefix_sum - q;

        ans += mp[complement];

        mp[prefix_sum]++;
    }

    cout << ans newline;
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