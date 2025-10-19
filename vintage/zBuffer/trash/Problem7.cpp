#include <bits/stdc++.h>
using namespace std;

#define AKY AayushKYadav ^_^

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define newline <<'\n'
#define all(x) (x).begin(),(x).end()
const int INF = LLONG_MAX >> 1;

bool isPrime(int n){
    if (n<2) return false;
    for (int i = 2; i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void solve() {


    vector<int> primelist;

    int i = 2;
    while(primelist.size()!=10002){
        if (isPrime(i)){
            primelist.push_back(i);
        }
        i++;
    }
    
    cout << primelist[10000];

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