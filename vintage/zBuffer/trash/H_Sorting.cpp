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
    for(auto &x:vecarr){cin >> x;}

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1; j++){
            if(vecarr[j]>vecarr[j+1]){
                swap(vecarr[j], vecarr[j+1]);
            }
        }
    }

    for(auto &x:vecarr){cout << x <<" ";}

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