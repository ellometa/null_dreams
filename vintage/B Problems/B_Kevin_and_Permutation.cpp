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
    int minimum = 0;
    
    vector<int> ans;
    int offset = n+1;
    for (int i = 0; i < n; i++){
        
        
        
        // for (int j = n; j > j-k; j--){
        //     cout << j << " ";
        // }
        
        
        //print the intermediary
        if ((i+1)%k == 0){
            if(minimum == 0){
                minimum+=1;
            }
            
            ans.push_back(minimum);
            // cout << minimum << " " ;
            minimum +=1;
            // offset +=1;
            // ans.push_back(n-i-1);
            // continue;
        }
        else{
            //print the max
            offset -=1;
            ans.push_back(offset);
            // cout << n-i << " ";
        }
        
        
        
        
    }
    
    
    for(int i = 0; i < n; i++){cout<< ans[i] << " ";}
    
    cout  newline;

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