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
    
    int curr; cin >> curr;
    int sum = 0;
    for (int i = 1 ; i < n; i++){
        int temp; cin >> temp;
        
        if (temp < curr){
            sum += curr-temp;
        }
        curr = max(curr, temp);
        
        
    }
    cout << sum;

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