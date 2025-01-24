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
    string s; cin >> s;
    
    string res;
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    res+=s[0];
    
    for (int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            res+=s[i];
        }
    }
    
    if(res =="meow"){
        cout << "YES" newline;
    }
    else{
        cout << "NO" newline;
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