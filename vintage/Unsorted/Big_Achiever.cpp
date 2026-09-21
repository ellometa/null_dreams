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
    vector<int> vecarr(n);
    for(auto &x:vecarr){cin>> x;}
    int maxn = 0;
    for (int i = 0; i < vecarr.size(); i++){
        
        if(vecarr[i]>maxn){
            maxn = vecarr[i];
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
        
    }
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