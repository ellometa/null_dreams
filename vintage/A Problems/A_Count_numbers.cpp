#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n, q; cin >> n >> q;
    
    vector<int> vecarr(n+1, 0);
    
    
    for (int i =0; i < q; i++){
        
        int a, b; cin >> a >> b;
        
        if (a == 1){
            vecarr[b]+=1;
        }
        else{
            cout << vecarr[b] newline;
        }
        
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