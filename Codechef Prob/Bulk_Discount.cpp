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
    
    sort(all(vecarr));
    
    
    int sum = vecarr[0];;
    
    for(int i = 1; i < n; i++){
        
        if ((vecarr[i]-1*i)<0){
            continue;
        }
        
        sum += (vecarr[i]-1*i);
        
    }
    
    cout << sum newline;

}

signed main() {
    IOS;

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}