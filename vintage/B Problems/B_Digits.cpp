#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n, d; cin >> n >> d;
    
    vector<int> factors;
    factors.push_back(1);
    
    if ( n >=3 || d%3 == 0){
        factors.push_back(3);
    }
    if (d ==5 ){
        factors.push_back(5);
    }
    if (n>=3 || d ==7){
        factors.push_back(7);
    }
    if( n>=6 || d==9 ||  (n>=3&&d%3==0)){
        factors.push_back(9);
    }  
    
    for (auto &x:factors){cout << x << " ";}  
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