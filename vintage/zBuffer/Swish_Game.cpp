#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int x, y; cin >> x >> y;
    
    string s; cin >> s;
    
    int swish = 0;
    
    for(int i =0; i < x; i++)  {
        if (s[i] == 'S'){
            swish+=1;
        }
    }
    
    if (swish >= y+1){
        cout << x newline; return;
    }
    
    cout << x+1 newline; return;
    
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