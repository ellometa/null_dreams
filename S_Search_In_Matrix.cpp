#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int x, y; cin >> x >> y;
    
    vector<int> freq(100001, 0);
    
    for (int i = 0; i < x*y; i++){
        int temp; cin >> temp;
        freq[temp]+=1;
    }
    
    int r; cin >> r;
    
    if (freq[r] == 0){
        cout << "will take number";
    }
    else{
        cout << "will not take number";
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