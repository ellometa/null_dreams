#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int k, s; cin >> k >> s;

    int count = 0;

    for (int x = 0; x <=k; x++){
        for (int y = 0; y <=k; y++){
            int z = s - (x+y);
            if(z>=0 && z<=k){
                count++;
            }
        }
    }

    cout << count newline;

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