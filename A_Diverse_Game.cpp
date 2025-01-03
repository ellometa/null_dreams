#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(null
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int x, y; cin >> x >> y;
    
    int n = x*y;
    
    vector<int> vecarr(n+1, 0);
    
    for(int i = 1; i<=n; i++){
        int temp; cin >> temp;
        vecarr[i]=temp;
    }
    
    vecarr[0] = vecarr[n];
    
    if (n==1){
        cout << -1; return;
    }
    
    for (int j = 0; j < n; j++){
        if (j%y == 0){
            cout newline;
            cout << vecarr[j] << " ";
            continue;
        }
        cout << vecarr[j] << " ";
    }
    // cout newline;
    
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