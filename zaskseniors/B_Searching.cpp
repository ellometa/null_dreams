#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int n; cin >>n;
    vector<int> vecarr(n);
    for(auto &x:vecarr){cin >> x;}

    int s; cin >> s;
    bool flag = false;
    int i=-1;
    for (auto &x:vecarr){
        ++i;
        if (x==s){
            flag = true;
            cout << i;
            return;
        }
    }
    
    cout << "-1";

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