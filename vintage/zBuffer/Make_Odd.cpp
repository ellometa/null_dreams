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
    string x, y; cin >> x >> y;
    int flipflag = 0, zerocount = 0, onecount = 0;
    
    for (int i = 0 ; i < n ; i++){
        
        if (x[i] != y[i]){
            // cout << x[i] << " " << y[i];
            flipflag+=1;
        }
        else if (x[i]=='0' && y[i]=='0'){
            zerocount+=1;
        }
        else{
            onecount+=1;
        }
    }
    
    if (flipflag>=1){
        cout << "YES" newline; return;
    }
    else if (onecount%2!=0 ){
        // cout << onecount << " ";
        cout << "YES" newline; return;
    }
    else{
        cout << "NO" newline; return;
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