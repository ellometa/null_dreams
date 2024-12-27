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
    
    int seg = 0;
    bool flag = false;
    
    for(int i =0; i<n; i++){
        if ( vecarr[i]!= 0 && !flag){
            seg+=1;
            flag = true;
        }
        if ( vecarr[i]==0 ){
            flag = false;
        }
        
    }
    
    if (seg > 2){
        cout << 2;
    }
    else{
        cout << seg;
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