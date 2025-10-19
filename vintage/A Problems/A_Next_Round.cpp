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
    int place; cin >> place;

    vector<int> vecarr(n);
    for(auto &x:vecarr){cin >> x;}
    int real = vecarr[place-1];

    int counter=0;

    for (int i = 0; i < n; i++){
        if (vecarr[i]>=real && vecarr[i]>0){
            ++counter;
        }
    }

    cout << counter;


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