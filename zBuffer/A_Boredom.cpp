#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x:arr){cin >> x;}

    sort(all(arr)); 

    for(auto &x:arr){cout << x-- << " " newline;}



}

signed main(){
    IOS;

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
