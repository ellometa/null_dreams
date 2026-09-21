#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n, m; cin >> n >> m;
    
    vector<int> person(n, 0), temp(n, 0);
    
    for (int i = 0 ; i < m ; i++){
        
        int id; string s; int time;
        cin >> id; cin >> s; cin >> time;
        --id;
        if ( s == "Enters"){
            temp[id] = time;
        }
        if (s == "Exit"){
            person[id] = person[id] + time - temp[id];
        }
        
    }
    
    for (auto &x:person){
        cout << x << " ";
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