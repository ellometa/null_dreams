#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int a,b; cin >> a;
    char c ; cin >> c>>b;
    
    
    if(c=='+'){
        cout << a+b;
    }
    else if(c=='-'){
        cout << a-b;
    }else if(c=='*'){
        cout << a*b;
    }else if(c=='/'){
        cout << a/b;
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