#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int w, b;
    cin >> w >> b;
    
    for(int i = 100000; i >= 0; i--){
        if( (1+i)*i/2 <= (w + b)){
            cout << i << endl;
            return;
        }
    }

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