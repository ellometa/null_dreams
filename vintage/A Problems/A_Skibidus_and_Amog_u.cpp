#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    string s; cin>>s;
    
    for (int i = 0; i < s.length()-1; i++){
        if ((s[s.length() - 2] == 'u' && s.length() - 2 == i) && (s[s.length() - 1] == 's')){
            cout << 'i';
            break;
        }
        cout << s[i];
    }
    cout newline;
    
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