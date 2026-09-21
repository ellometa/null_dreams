#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve(){
    int n, y; cin >> n >> y;
    int counter = 1;
    while (n--){
        int x; cin >> x;
        if (x == y){
            cout << counter; return;
        }
        counter+=1;
    }
    
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
