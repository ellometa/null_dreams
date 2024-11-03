#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;


void solve() {

    int n; cin >>n;
    int counter = 0;
    for(int i = 1; i <= (n+1/2); i++){
        if (n%i==0){
            ++counter;
        }
        else{
            break;
        }
    }
    cout << counter newline;
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