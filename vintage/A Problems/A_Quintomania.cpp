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
    for(auto &x : vecarr){cin >> x;}
    bool flag = true;

    for(int i = 0; i < n-1; i++){
        int diff = abs(vecarr[i]-vecarr[i+1]);
        if (diff == 7||diff == 5){
            continue;
        }
        else{
            cout << "NO" newline;
            return;
        }
    }
    cout << "YES" newline;

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