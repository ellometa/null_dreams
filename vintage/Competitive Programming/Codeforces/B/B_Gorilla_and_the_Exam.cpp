#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve() {

    int n, k; cin >> n >> k;
    
    multiset<int> ms;
    unordered_set<int> setta;
    
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        ms.insert(temp);
        setta.insert(temp);
    }
    
    if (n==1){cout << 1 newline; return;}

    vector<int> counts;
    if (k==0){
        cout << setta.size() newline; return;
    }
    
    for (auto it=ms.begin(); it!=ms.end();){
        int value = *it;
        int count = ms.count(value);
        counts.push_back(count);
        it = ms.upper_bound(value);
    }
    sort(all(counts));
    
    vector<int> pref(counts.size()+1, 0);
    
    for (int i = 1; i <= counts.size()+1; i++){
        pref[i] = pref[i-1] + counts[i-1];
    }
    
    
    auto lb = lower_bound(all(pref), k);
    
    int index = lb - pref.begin();
    
    
    
    
    cout << counts.size()-index newline;
    
    // for(auto &x:pref){
    //     cout << x << " ";
    // }
    // cout newline;
    

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