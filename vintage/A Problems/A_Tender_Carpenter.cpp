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
    
    //find the max elements
    bool flag = false;
    
    for(int i =0; i<n-1; i++){
        int minel = min(vecarr[i], vecarr[i+1]);
        int maxel = max(vecarr[i], vecarr[i+1]);
        
        if ((2*minel - maxel) > 0 ){
            flag = true;
        }
    }
    
    if (flag){cout << "YES" newline;}
    else{ cout << "NO" newline;}
    
    
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