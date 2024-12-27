#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    string s; cin >> s;
    int count = 0;
    int lmax = 0;
    
    for (int i = 0; i < s.size(); i++){
        
        if (s[i]==s[i+1]){
            count+=1;
        }
        else{
            lmax = max(lmax, count);
            count = 0;
        }
        
    }
    cout << lmax+1;
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