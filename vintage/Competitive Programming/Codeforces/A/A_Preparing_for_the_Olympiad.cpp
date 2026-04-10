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
    vector<int> va;
    va.push_back(0);
    for(int i = 1; i < n+1; i++){
        int temp; cin>> temp;
        va.push_back(temp);
    }
    

    // for (auto &x:vecarr){ cout << x newline;}
    
    // for (auto &x:va){ cout << x newline;}
    
    vector<int> vb;
    for(int i = 0; i < n; i++){
        int temp; cin>> temp;
        vb.push_back(temp);
    }
    vb.push_back(0);
    
    int sum = 0;
    for (int i = 0; i<=n; i++){
        // cout << "VA " << va[i] << " VB " << vb[i] newline; 
        if(va[i]>vb[i]){
            sum+=(va[i]-vb[i]);
        }
    }
    
    cout << sum newline;
    
    
    

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