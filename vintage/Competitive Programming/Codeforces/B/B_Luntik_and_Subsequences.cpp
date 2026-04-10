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
    vector<int> vecarr(n, 0);
    int sum = 0, zerocount = 0, onecount=0;
    
    for(auto &x:vecarr){
        cin>> x;
        
        sum+=x;

        if (x == 0){
            zerocount +=1;
        }
        else if (x == 1){
            onecount +=1;
        }
        
    }
    sort (all(vecarr));
    int power = (int)(pow(2,zerocount));
    cout << (zerocount==0? onecount : onecount*power);
    
    
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