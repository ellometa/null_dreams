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
    for (auto &x:vecarr){cin >> x;}
    bool flag = true;
    for (int i = 0; i < (n/2+1); i++){
        if(vecarr[i]!=vecarr[n-i-1]){
            flag = false;
            break;
        }
    }
    flag?cout<<"YES":cout<<"NO" ;

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