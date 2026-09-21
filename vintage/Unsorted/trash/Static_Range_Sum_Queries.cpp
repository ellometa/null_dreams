#include <bits/stdc++.h>
using namespace std;
 
#define AKY AayushKYadav ^_^
 
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;
 
void solve() {
 
    int n, q; cin >> n >> q;
 
    vector<int> vecarr(n);
    for(auto &x:vecarr){cin>> x;}
 
    vector<int> prefsum(n+1, 0);
 
    for (int i = 0; i < n+1; i++){
        prefsum[i+1]=prefsum[i] + vecarr[i];
    }
 
    // for (auto &x:prefsum){ cout << x << " ";}
 
    for (int i = 0; i < q; i++) {
 
        int a, b; cin >> a >> b;
 
        int ans = prefsum[b] - prefsum [a-1];
        cout << ans newline;
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