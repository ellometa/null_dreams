#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
// #define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int n; cin >> n;
    
    string s; cin >> s;
    
    for (int i = 0 ; i < n ; i++){
        char c = s[i];
        // int n = int(c);
        
        if ( iswalnum(c) ){ continue; }
        cout << s[i];
    }
    

}

int main() {
    IOS;

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}