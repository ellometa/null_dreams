#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    string str; cin >> str;
    
    int l = str.length();
    
    int zpos=-1;
    
    for(int i = 0; i < l; i++){
        if (str[i] == '0'){
            zpos = i;
            break;
        }
    }
        
    if (zpos == -1){ zpos = l-1;}
    
    int k = zpos - 1;
    int j;
    
    for (j = zpos; j < l && k >= 0; j += 1, k -= 1) {
        if (str[j] == '1') {
            break;
        }
    }
    
    k += 1;
    
    cout << 1 << " " << l << " " << k + 1 << " " << k + l - zpos;      
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