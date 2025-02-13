#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline << '\n'
#define all(x) (x).begin(), (x).end()
const int INF = LLONG_MAX >> 1;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> veca; 
    int maxtotal = 0;

    for (int i = 0; i < n; i++){
        int sum = 0, comb = 0;
        for (int j = 0; j < m; j++){
            int x; cin >> x;
            sum += x;
            // 2 4 6 8
            // 3 5 6 8
            // 4 5 7 8
            comb += sum;
            // 2 6 12 20
            // 3 8 14 22
            // 4 9 16 24
        }
        maxtotal += comb;
        // 20 42 66
        veca.push_back({sum, comb});
        // 8, 20
        // 8, 22
        // 8, 24
        
    }
    
   
    

    
    sort(all(veca), greater<>());
    // 8, 24
    // 8, 22
    // 8, 20


    int extra = 0;
    
    for (int i = 0; i < n; i++){
        
        int esum = veca[i].first;
        // 8, 24
        int y = n-i-1;
        extra = extra + (y * esum);
        //  0  + 2*8
        //  16 + 1*8
        //  24 + 0*8
    } 
    cout << maxtotal + extra*m newline;
    //      66 + 24*4
}

int32_t main() {
    IOS;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
