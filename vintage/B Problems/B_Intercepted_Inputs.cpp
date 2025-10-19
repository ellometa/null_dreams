#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n; cin>>n;

    vector<int> vecarr(n);

    for(auto &x:vecarr){cin >> x;}

    sort (all(vecarr));

    //find factors of n-2

    int actual = n-2;

    for(int i = 1; i < (actual/2 + 2); i++){
        // cout << actual << " " << i << " space" newline;
        if (actual%i==0){
            
            int key = i;
            auto it = find(all(vecarr), key);
            auto it2 = find(all(vecarr), actual/key);
            if ((it != vecarr.end())&&it2!=vecarr.end()){
                cout << key << " " << actual/key newline;
                return;
            }

        }
    }




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