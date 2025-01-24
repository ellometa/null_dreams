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
    if (n==1){ cout << 1; return;}
    
    if (n<4){
        cout << "NO SOLUTION";
        return;
    }    
    
    
    for (int i =2; i <= n; i+=2){
        cout << i << " ";
    }
    for (int i = 1; i <=n; i+=2){
        cout << i << " ";
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