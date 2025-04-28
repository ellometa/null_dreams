#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

void solve(){
    
    vector<int> num(3, 0);
    for (auto &x:num){cin >> x;}
    
    sort (all(num));

    num[2] = 0;
    
    if (num[0]%2 ==1 && num[1]%2==1){
        cout << num[1] + num[0] -1 newline;
        return;
    }
    cout << num[1] + num[0] newline;
    // if (num[0]%2 == 0){
    //     cout << num[1] + num[0] newline;
    // }
    // else{
    //     cout << num[1]+num[0] newline;
    // }
    
    


}

signed main(){
    IOS;

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
