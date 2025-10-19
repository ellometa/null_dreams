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
    int sum; cin >> sum;
 
    vector<int> vecarr(n);
    for(auto &x:vecarr){cin>> x;}
    // sort(all(vecarr));
    vector<int> prefsum(n+1, 0);
    for (int i = 0; i < n+1; i++){
        prefsum[i+1]=prefsum[i] + vecarr[i];
    }

    prefsum.erase(prefsum.begin());
    for (auto &x:prefsum){ cout << x << " ";}
 
    int counter = 0;
    
    for (int i =0 ; i < n; i++){
        
        for (int j = i; j <n; j++){
            if ( prefsum[j+1] - prefsum[i]== sum){
                counter+=1;
            }
        }
    }
    cout << counter newline;
 
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