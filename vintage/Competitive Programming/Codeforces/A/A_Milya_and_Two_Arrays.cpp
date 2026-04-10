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
    vector<int> va(n);
    for(auto &x:va){cin>> x;}
    sort(all(va));
    
    vector<int> vb(n);
    for(auto &x:vb){cin>> x;}
    sort(all(v));
    
    
    int tempa = va[0];
    int countera = 1;
    
    for (auto &x:va){
        if (tempa !=x){
            countera+=1;
        }
        tempa = x;
    }
    
    int tempb = vb[0];
    int counterb = 1;
    
    for (auto &x:vb){
        if (tempb !=x){
            counterb+=1;
            // cout << x << " new" newline;
        }
        tempb = x;
    }
    
    if (countera+counterb < 4){
        cout<<"NO" newline;
    }
    else{
        cout << "YES" newline;
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