#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n; cin >> n; int temp = n;
    int rem = 0;

    while(n>0){
        int digit = n%10;
        rem = rem*10 + digit;
        n=n/10;
    }    
    cout << rem newline;
    rem==temp?cout << "YES" :cout << "NO";

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