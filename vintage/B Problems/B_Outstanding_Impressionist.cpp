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
    
    vector<int> v;
    
    vector<int> singleton(100001, 0);
    
    for(int i = 0 ; i < n; i++){
        int l, r; cin >> l >> r;
        
        v.push_back(l); v.push_back(r);
        
        if (l == r){
            singleton[l]+=1;
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < n; i++){
        int la = v[2*i];
        int ra = v[2*i + 1];
        
        if (la == ra){
            //check if singleton at that position is greater than 1, because this is one of the singletons as well
            
            if (singleton[la] == 1){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
            continue;
            
        }
        bool flag = false;
        for (int j = la; j <= ra; j++){
            if (singleton[j] == 0){
                ans.push_back(1);
                flag = true;
                break;
            }
        }
        if (!flag){ans.push_back(0);}
    }    
    
    for(auto &x:ans){cout<<x;}
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