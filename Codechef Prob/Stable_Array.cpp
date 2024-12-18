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
    
    int maxtemp = -INF;
    int temppref = 0;
    
    vector<int> prefs;
    
    for(int i = n-1; i >= 0; i--){
        
        int currloc = i;
        
        if (vecarr[currloc] >= maxtemp){
            maxtemp = vecarr[currloc];
            prefs.push_back(temppref);
            temppref=0;
        }
        else if (vecarr[currloc] < maxtemp){
            temppref+=1;
        }
        
    }
    
    prefs.push_back(temppref);
    
    cout << *max_element(all(prefs)) newline;
    

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