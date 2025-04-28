#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int counter=0, gcount = 0, bcount = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'G'){
            gcount +=1;
        }
        else{
            bcount +=1;
        }
        
        if (bcount > 2*gcount){
            cout << bcount + gcount newline;
            return;
        }
    }
    cout << bcount + gcount newline;
}

signed main(){
    IOS;

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
