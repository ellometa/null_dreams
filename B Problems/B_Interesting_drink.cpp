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
    vector<int> vecarr(n);
    for(auto &x:vecarr){cin>> x;}

    sort(all(vecarr));

    int days; cin >> days;

    for(int i = 0; i < days; i++){
        int target; cin >> target;
        auto it = upper_bound(all(vecarr), target);
        int index = it - vecarr.begin();
        cout << index newline;
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