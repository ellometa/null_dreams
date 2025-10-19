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
    
    vector<int> freq(100001, 0);
    int sum = 0;
    
    for (int i = vecarr.size()-1; i >=0; i--){
        
        int day =vecarr[i];
        if(freq[day] == 1){continue;}
        freq[day] = 1;
        sum += (i+1);
        
    }
    
    cout << sum newline;
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